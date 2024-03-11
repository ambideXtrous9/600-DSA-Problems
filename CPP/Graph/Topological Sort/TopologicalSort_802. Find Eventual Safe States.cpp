#include <bits/stdc++.h>

using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &G)
{
    int n = G.size();

    vector<int> adj[n];

    vector<int> indegree(n, 0);

    // reverse the Graph and calculate the indegree

    for (int i = 0; i < n; i++) 
    {
        for (auto v : G[i])
        {
            indegree[i]++;
            adj[v].push_back(i);
        }
    }

    queue<int> Q;

    // then apply topological sort

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            Q.push(i);

    while (!Q.empty()) // apply BFS topological sort
    {
        auto u = Q.front();
        Q.pop();

        for (auto v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
                Q.push(v);
        }
    }

    vector<int> V;

    // store nodes with 0 indegree

    for (int i = 0; i < n; i++)  
        if (indegree[i] == 0)
            V.push_back(i);

    return V;
}