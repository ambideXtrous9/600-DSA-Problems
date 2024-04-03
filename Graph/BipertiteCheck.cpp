#include <bits/stdc++.h>

using namespace std;

// BFS IMPLEMENTATION FOR BIPARTITE:
bool BFS(int s, vector<int> &vis, vector<int> adj[])
{
    queue<int> q;
    q.push(s);
    
    vis[s] = 1;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (vis[v] == -1)
            {
                vis[v] = ~vis[u];
                q.push(v);
            }
    
            else if (vis[v] == vis[u])
                return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> vis(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            if (!BFS(i, vis, adj))
                return false;
        }
    }
    return true;
}

// DFS IMPLEMENTATION FOR BIPARTITE:

bool dfs(int u, vector<int> adj[], vector<int> &color)
{
    for (auto v : adj[u])
    {
        if (color[v] == -1)
        {
            color[v] =  ~color[u];
            if (!dfs(v, adj, color))
            {
                return false;
            }
        }
        else if (color[v] == color[u])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!dfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}