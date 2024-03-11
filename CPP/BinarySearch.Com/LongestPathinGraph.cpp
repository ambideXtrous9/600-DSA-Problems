#include <bits/stdc++.h>

using namespace std;

// BFS + Topological Sort
int solve(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> indegree(n, 0);
    vector<int> dist(n, 0);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto v : graph[i])
        {
            indegree[v]++;
        }
    }

    queue<pair<int, int>> Q; // node + dist;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push({i, 0});
        }
    }

    while (!Q.empty())
    {
        auto [u, dis] = Q.front();
        Q.pop();

        dist[u] = dis;
        ans = max(ans, dist[u]); // calc max distance

        for (auto v : graph[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
            {
                Q.push({v, dis + 1});
            }
        }
    }

    return ans;
}

// DFS Based Solution
void TopoOrder(vector<vector<int>> &G, int s, stack<int> &S, vector<int> &vis)
{
    vis[s] = true;

    for (auto v : G[s])
    {
        if (!vis[v])
        {
            TopoOrder(G, v, S, vis);
        }
    }

    S.push(s);
}

int solve(vector<vector<int>> &graph)
{
    int n = graph.size();
    stack<int> S;
    vector<int> vis(n, 0);
    vector<int> dist(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            TopoOrder(graph, i, S, vis);
    }

    int ans = 0;

    while (!S.empty())
    {
        int u = S.top();
        S.pop();

        for (auto X : graph[u])
        {
            int v = X;

            if (dist[v] < dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                ans = max(ans, dist[v]);
            }
        }
    }

    return ans;
}

int DFS(vector<vector<int>> &G, int s, vector<int> &dp)
{

    int n = G[s].size();

    if (n == 0)
        return dp[s] = 0;

    if (dp[s] != -1)
        return dp[s];

    int ans = 0;

    for (int i = 0; i < G[s].size(); i++)
    {
        ans = max(ans, 1 + DFS(G, G[s][i], dp));
    }
    return dp[s] = ans;
}

int solve(vector<vector<int>> &G)
{

    int n = G.size();

    vector<int> dp(n, -1);

    vector<int> IN(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (auto v : G[i])
        {
            IN[v]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (IN[i] == 0)
            ans = max(ans, DFS(G, i, dp));
    }

    return ans;
}