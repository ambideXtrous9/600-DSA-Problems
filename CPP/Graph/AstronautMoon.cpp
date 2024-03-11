#include <bits/stdc++.h>

using namespace std;

void DFS(vector<int> adj[], vector<bool> &vis, int s, long &res)
{
    vis[s] = true;
    res += 1;
    for (auto v : adj[s])
    {
        if (!vis[v])
        {
            DFS(adj, vis, v, res);
        }
    }
}

long journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<int> adj[n];
    int c = astronaut.size();

    for (int i = 0; i < c; i++)
    {
        adj[astronaut[i][0]].push_back(astronaut[i][1]);
        adj[astronaut[i][1]].push_back(astronaut[i][0]);
    }

    vector<bool> vis(n, false);

    long sum = 0;
    long res = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            long comp = 0;
            DFS(adj, vis, i, comp);

            res += sum * comp;
            sum += comp;
        }
    }

    return res;
}