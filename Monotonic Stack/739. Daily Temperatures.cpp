#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &T)
{
    // NGR

    int n = T.size();

    stack<pair<int, int>> S;

    vector<int> V(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top().first <= T[i])
        {
            S.pop();
        }

        if (!S.empty())
        {
            V[i] = (S.top().second - i);
        }

        S.push({T[i], i});
    }

    return V;
}