#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();

    vector<int> ML(n, 0);
    vector<int> MR(n, 0);

    ML[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        ML[i] = max(ML[i - 1], height[i]);
    }

    MR[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        MR[i] = max(MR[i + 1], height[i]);
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += min(ML[i], MR[i]) - height[i];
    }

    return sum;
}