#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> v;

/*

dist based priority queue wont work here
so instead of Djkstra 

use BFS based on queue + stop at priority

*/

int findCheapestPrice(int n, vector<vector<int>> &F, int s, int d, int k)
{
    vector<pi> adj[n];

    for (auto x : F)
    {
        adj[x[0]].push_back({x[1], x[2]});
    }

    queue<v> Q;

    vector<int> dist(n, INT_MAX);

    dist[s] = 0;

    Q.push({0, s, 0});

    while (!Q.empty())
    {
        auto x = Q.front();
        Q.pop();

        int stop = x[0];
        int u = x[1];
        int cost = x[2];

        if (stop > k)
            continue;

        for (auto it : adj[u])
        {
            auto [v, w] = it;

            if (stop <= k && dist[u] != INT_MAX && dist[v] > cost + w)
            {
                dist[v] = cost + w;
                Q.push({stop + 1, v, dist[v]});
            }
        }
    }

    return dist[d] == INT_MAX ? -1 : dist[d];
}

typedef pair<int, int> PI;

void addEdge(unordered_map<int, vector<PI>> &adj, int u, int v, int weight)
{
    adj[u].emplace_back(make_pair(v, weight));
}

// Not Optimized

int DFS(unordered_map<int, vector<PI>> &adj, vector<bool> &vis, int s, int d, int k)
{
    if (s == d && k >= 0)
        return 0;
    if (k <= 0)
        return 1e9;

    int ans = 1e9;

    vis[s] = true;
    for (auto X : adj[s])
    {

        int v = X.first;
        int w = X.second;

        if (!vis[v])
        {

            int res = w + DFS(adj, vis, v, d, k - 1);
            ans = min(ans, res);
        }
    }
    vis[s] = false;
    return ans;
}

// More Optimized
void DFS(unordered_map<int, vector<PI>> &adj, vector<bool> &vis, int s, int d, int k, int &ans, int cost)
{
    if (s == d && k >= 0)
    {
        ans = cost;
        return;
    }
    if (k <= 0)
        return;

    vis[s] = true;
    for (auto X : adj[s])
    {

        int v = X.first;
        int w = X.second;

        if (!vis[v] && cost + w < ans)
        {

            DFS(adj, vis, v, d, k - 1, ans, cost + w);
        }
    }
    vis[s] = false;
}

// BFS Solution

int BFS(int K, int s, int d, unordered_map<int, vector<PI>> &adj)
{
    int ans = INT_MAX;
    queue<PI> q;

    q.push({s, 0});
    int steps = 0;

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; ++i)
        {
            auto curr = q.front();
            q.pop();

            if (curr.first == d)
                ans = min(ans, curr.second);

            for (auto x : adj[curr.first])
            {
                if (curr.second + x.second > ans)
                    continue;
                q.push({x.first, curr.second + x.second});
            }
        }
        if (steps++ > K)
            break;
    }

    return ans == INT_MAX ? -1 : ans;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    unordered_map<int, vector<PI>> adj;
    vector<bool> vis(n, false);

    for (int i = 0; i < flights.size(); i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];

        addEdge(adj, u, v, w);
    }
    int ans = INT_MAX;
    int cost = 0;

    DFS(adj, vis, src, dst, k + 1, ans, cost);

    return (ans == INT_MAX) ? -1 : ans;
}

// Bellman-Ford

int findCheapestPrice(int n, vector<vector<int>> &flights, int s, int d, int K)
{
    const int INF = 1e9;
    vector<vector<int>> dp(K + 2, vector<int>(n, INF));
    dp[0][s] = 0;
    for (int i = 1; i <= K + 1; i++)
    {
        dp[i][s] = 0;
        for (const auto &x : flights)
        {
            dp[i][x[1]] = min(dp[i][x[1]], dp[i - 1][x[0]] + x[2]);
        }
    }
    return dp[K + 1][d] >= INF ? -1 : dp[K + 1][d];
}