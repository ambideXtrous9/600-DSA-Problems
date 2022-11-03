#include <bits/stdc++.h>

using namespace std;

// LC : 785. Is Graph Bipartite?

bool BP_BFS(vector<vector<int>> &G, int s, vector<int> &color)
{
    queue<int> Q;

    Q.push(s);
    color[s] = 1;

    while (!Q.empty())
    {
        auto u = Q.front();
        Q.pop();

        for (auto v : G[u])
        {
            if (color[v] == -1)
            {
                color[v] = ~color[u];

                Q.push(v);
            }
            else if (color[v] == color[u])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &G)
{

    int n = G.size();

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!BP_BFS(G, i, color))
                return false;
        }
    }

    return true;
}