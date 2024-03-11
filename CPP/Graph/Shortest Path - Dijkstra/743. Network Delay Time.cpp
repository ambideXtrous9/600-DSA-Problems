#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PI;

void addEdge(int u, int v, int w, vector<PI> adj[])
{
    adj[u].push_back({v, w});
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{

    vector<PI> adj[n + 1];

    vector<int> dist(n + 1, INT_MAX);

    for (auto x : times)
    {
        addEdge(x[0], x[1], x[2], adj);
    }

    priority_queue<PI, vector<PI>, greater<PI>> Q;

    dist[k] = 0;

    Q.push({0, k});

    while (!Q.empty())
    {
        auto [wt, u] = Q.top();
        Q.pop();

        for (auto X : adj[u])
        {
            auto [v, w] = X;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;

                Q.push({dist[v], v});
            }
        }
    }

    int ans = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }
    return ans == INT_MAX ? -1 : ans;
}