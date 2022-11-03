#include <bits/stdc++.h>

using namespace std;

void addedge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}


// nodes start with 1 -> changed index accordingly


vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    vector<int> adj[n + 1];

    vector<int> times(n, 0);

    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        addedge(edges[i][0], edges[i][1], adj);

        indegree[edges[i][1]]++;
    }

    queue<int> Q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
            times[i - 1] = 1;
        }
    }

    while (!Q.empty())
    {
        auto u = Q.front();
        Q.pop();

        for (auto v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
            {
                Q.push(v);

                times[v - 1] = 1 + times[u - 1];
            }
        }
    }

    return times;
}