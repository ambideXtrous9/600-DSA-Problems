#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PI;

void addEdge(int u, int v, int w, vector<PI> adj[])
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int solve(vector<vector<int>> &edges)
{
    int n = 0;
    for (auto edge : edges)
    {
        n = max(n, edge[0]);
        n = max(n, edge[1]);
    }
    n++;

    priority_queue<PI, vector<PI>, greater<PI>> Q;

    vector<PI> adj[n];

    for (int i = 0; i < edges.size(); i++)
    {
        addEdge(edges[i][0], edges[i][1], edges[i][2], adj);
    }

    vector<int> dist(n, INT_MAX);
    vector<int> path(n, 0);

    vector<int> orderv;

    Q.push({0, n - 1});

    dist[n - 1] = 0;
    path[n - 1] = 1;

    while (!Q.empty())
    {
        int val = Q.top().first;
        int u = Q.top().second;

        Q.pop();

        if (val != dist[u])
            continue;

        orderv.push_back(u);

        for (auto x : adj[u])
        {
            int dis = x.second;
            int v = x.first;

            if (dist[v] > dist[u] + dis)
            {
                dist[v] = dist[u] + dis;

                Q.push({dist[v], v});
            }
        }
    }

    vector<int> dp(n, 0);

    dp[n - 1] = 1;
    const int MOD = 1e9 + 7;

    for (auto u : orderv)
    {
        for (auto X : adj[u])
        {
            int v = X.first;

            if (dist[v] < dist[u])
            {
                dp[u] += dp[v];
                dp[u] %= MOD;
            }
        }
    }

    return dp[0];
}
typedef pair<int, int> PI;

void addEdge(int u, int v, int w, vector<PI> adj[])
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int solve(vector<vector<int>> &edges)
{
    int n = 0;
    for (auto edge : edges) // count total no of nodes
    {
        n = max(n, edge[0]);
        n = max(n, edge[1]);
    }
    n++;

    priority_queue<PI, vector<PI>, greater<PI>> Q;

    vector<PI> adj[n];

    for (int i = 0; i < edges.size(); i++)
    {
        addEdge(edges[i][0], edges[i][1], edges[i][2], adj);
    }

    vector<int> dist(n, INT_MAX);
    vector<int> path(n, 0);

    vector<int> orderv;

    Q.push({0, n - 1});

    dist[n - 1] = 0; // start from home

    while (!Q.empty())
    {
        int val = Q.top().first;
        int u = Q.top().second;

        Q.pop();

        if (val != dist[u])
            continue;

        orderv.push_back(u); // store nodes based on close proximity to home

        for (auto x : adj[u])
        {
            int dis = x.second;
            int v = x.first;

            if (dist[v] > dist[u] + dis)
            {
                dist[v] = dist[u] + dis;

                Q.push({dist[v], v});
            }
        }
    }

    path[n - 1] = 1;
    const int MOD = 1e9 + 7;

    for (auto u : orderv)
    {
        for (auto X : adj[u])
        {
            int v = X.first;

            // You can go from u to v if it's immediately connected and
            // the shortest distance from u to home is larger than
            // the shortest distance from v to home.

            if (dist[v] < dist[u])
            {
                path[u] += path[v];
                path[u] %= MOD;
            }
        }
    }

    return path[0];
}