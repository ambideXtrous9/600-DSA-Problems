#include <bits/stdc++.h>

using namespace std;

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}

bool DFS_Cycle(vector<int> adj[], int s, vector<bool> &vis, vector<bool> &Stack)
{
    vis[s] = true;
    Stack[s] = true;

    for (auto v : adj[s])
    {
        if (!vis[v])
        {
            if (DFS_Cycle(adj, v, vis, Stack))
            {
                return true;
            }
        }
        else if (Stack[v] == true)
        {
            return true;
        }
    }

    return Stack[s] = false;
}

bool canFinish(int n, vector<vector<int>> &G)
{

    vector<bool> vis(n, false);
    vector<bool> Stack(n, false);
    vector<int> adj[n];

    for (int i = 0; i < G.size(); i++)
    {
        addEdge(G[i][1], G[i][0], adj);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (DFS_Cycle(adj, i, vis, Stack))
            {
                return false;
            }
        }
    }

    return true;
}