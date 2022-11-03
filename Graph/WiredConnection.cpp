#include <bits/stdc++.h>

using namespace std;

// DFS

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    visited[src] = true;
    
    for (int i : adj[src])
    {
        if (!visited[i])
        {
            dfs(adj, visited, i);
        }
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{

    if (connections.size() < n - 1)
        return -1;
    
    vector<vector<int>> adj(n);

    for (auto v : connections)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    vector<bool> visited(n, false);
    int components = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, i);
            components++;
        }
    }

    return components - 1;
}

// Union Find

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<int> parent(n);

    int c = connections.size();
    if (n - 1 > c)
        return -1;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    vector<int> rank(n, 0);

    int cost = 0;
    for (int i = 0; i < c; i++)
    {
        int u = findPar(connections[i][0], parent);
        int v = findPar(connections[i][1], parent);

        if (u != v)
        {
            unionn(u, v, parent, rank);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            cost++;
    }

    return cost - 1;
}