#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int Dijkstra(vector<pi> adj[], int s, unordered_set<int> &M, int n, int m)
{
    vector<int> dist(n, INT_MAX);

    priority_queue<pi, vector<pi>, greater<pi>> Q;

    dist[s] = 0;

    Q.push({dist[s], s});

    int ans = INT_MAX;

    vector<int> vis(n, false);

    while (!Q.empty() && m)
    {
        auto [val, u] = Q.top();
        Q.pop();

        if (vis[u])
            continue;

        if (val != 0 && M.find(u) != M.end())
        {
            ans = min(ans, val);
            m -= 1;
        }

        vis[u] = true;

        for (auto X : adj[u])
        {
            auto [v, w] = X;
            if (!vis[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> node(m);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        node[i] = x;
    }

    vector<pi> adj[n];
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    unordered_set<int> M(node.begin(), node.end());

    int ans = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        int cur = Dijkstra(adj, node[i], M, n, m);
        ans = min(ans, cur);
    }

    cout << ans << endl;

    return 0;
}