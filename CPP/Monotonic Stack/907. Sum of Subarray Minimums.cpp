#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

void NSL(vector<int> &arr, vector<int> &L)
{
    int n = arr.size();

    stack<pair<int, int>> S;

    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && S.top().first >= arr[i])
        {
            S.pop();
        }

        if (!S.empty())
        {
            L[i] = i - S.top().second;
        }
        else
            L[i] = i + 1;

        S.push({arr[i], i});
    }
}

void NSR(vector<int> &arr, vector<int> &R)
{
    int n = arr.size();

    stack<pair<int, int>> S;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top().first > arr[i])
        {
            S.pop();
        }

        if (!S.empty())
        {
            R[i] = S.top().second - i;
        }
        else
            R[i] = n - i;

        S.push({arr[i], i});
    }
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();

    vector<int> L(n, 0);
    vector<int> R(n, 0);

    NSL(arr, L);
    NSR(arr, R);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        long long x = (L[i] * R[i]) % mod;
        x = (x * arr[i]) % mod;
        res = (res + x) % mod;
    }

    return res;
}