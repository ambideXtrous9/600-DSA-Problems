#include <bits/stdc++.h>

using namespace std;

// uber mein aaya tha

static bool comp(vector<int> &a, vector<int> &b) //
{
    if (a[0] == b[0])
        return a[1] > b[1];

    return a[0] < b[0];
}

int LIS(vector<vector<int>> &env)
{
    int n = env.size();

    vector<int> V;

    V.push_back(env[0][1]);

    for (int i = 1; i < n; i++)
    {
        if (V.back() < env[i][1])
        {
            V.push_back(env[i][1]);
        }
        else
        {
            int idx = lower_bound(V.begin(), V.end(), env[i][1]) - V.begin();

            V[idx] = env[i][1];
        }
    }

    return V.size();
}
int maxEnvelopes(vector<vector<int>> &env)
{
    // sort based on width, if width same then take greater height first
    // for dry run see -> {{4, 3}, {5, 3}, {5, 6}, {1, 2}}
    // then apply LIS.

    sort(env.begin(), env.end(), comp);

    return LIS(env);
}