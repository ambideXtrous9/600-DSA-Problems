#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &parent, vector<int> &values)
{
    int n = parent.size();
    int root;
    vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
            root = i;

        else
            adj[parent[i]].push_back(i);
    }

    vector<int> dp(n, INT_MIN);
    vector<bool> vis(n, false);

    queue<pair<int, int>> Q;

    dp[root] = values[root];

    vis[root] = true;

    Q.push({root, dp[root]});

    int ans = INT_MIN;

    while (!Q.empty())
    {
        int u = Q.front().first;
        Q.pop();

        ans = max(ans, dp[u]);

        for (auto v : adj[u])
        {
            vis[v] = true;
            dp[v] = max(values[v], dp[u] + values[v]);
            Q.push({v, dp[v]});
        }
    }

    return ans;
}

int main()
{
    vector<int> parent{-1, 0, 1, 2, 0};
    vector<int> values{-2, 10, 10, -3, 10};

    int x = solve(parent, values);

    cout << x << endl;
}