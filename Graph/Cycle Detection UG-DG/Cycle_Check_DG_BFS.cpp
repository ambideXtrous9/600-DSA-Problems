#include <bits/stdc++.h>

using namespace std;

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}

bool topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    vector<int> node;

    for (int i = 0; i < V; i++) // compute the indegree
    {
        for (auto v : adj[i])
        {
            indegree[v]++;
        }
    }

    queue<int> Q;

    for (int i = 0; i < V; i++) // push node to Q with indegree = 0
    {
        if (indegree[i] == 0)
            Q.push(i);
    }

    int count = 0;

    while (!Q.empty()) // apply BFS
    {
        int u = Q.front();

        Q.pop();

        count++;

        for (auto v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0) // push to queue only if indegree[v] == 0
            {
                Q.push(v);
            }
        }
    }

    return count != V; // if cycle present then count<V as toposort valid for DAG
}