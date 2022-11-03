#include <bits/stdc++.h>

using namespace std;

vector<int> NSL(vector<int> &arr)
{
    int n = arr.size();

    vector<int> V(n, -1);

    stack<pair<int, int>> S;

    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && S.top().first >= arr[i])
        {
            S.pop();
        }

        if (!S.empty())
            V[i] = S.top().second;

        S.push({arr[i], i});
    }

    return V;
}

vector<int> NSR(vector<int> &arr)
{
    int n = arr.size();

    vector<int> V(n, n);

    stack<pair<int, int>> S;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top().first >= arr[i])
        {
            S.pop();
        }

        if (!S.empty())
            V[i] = S.top().second;

        S.push({arr[i], i});
    }

    return V;
}

int largestRectangleArea(vector<int> &heights)
{

    vector<int> nsl = NSL(heights);
    vector<int> nsr = NSR(heights);

    int ans = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        ans = max(ans, (nsr[i] - nsl[i] - 1) * heights[i]);
    }

    return ans;
}