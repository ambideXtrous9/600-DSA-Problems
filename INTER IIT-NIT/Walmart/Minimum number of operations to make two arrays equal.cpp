#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int diff = 2;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += abs(arr1[i] - arr2[i]);
    }

    int res = sum / (2 * diff);

    return res;
}