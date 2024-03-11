#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<int> tin;
vector<int> low;
vector<int> articul;

int timer = 0;
int node = 0;

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<int> adj[], int s, int par)
{
    vis[s] = true;
    tin[s] = low[s] = timer++;

    int child = 0;

    for (auto it : adj[s])
    {
        if (it == par)
            continue;

        if (!vis[it])
        {
            DFS(adj, it, s);

            low[s] = min(low[s], low[it]);

            child++;

            if (low[it] >= tin[s] && par != -1)
            {
                articul[s] = 1;
                node++;
            }
        }
        else
        {
            low[s] = min(low[s], tin[it]);
        }
    }

    if (par == -1 && child > 1)
    {
        articul[s] = 1;
        node++;
    }
}

int main()
{
    int n = 5;

    vector<vector<int>> V = {{1, 2}, {2, 3}, {3, 4}, {1, 5}};

    vector<int> G[n + 1];

    for (int i = 0; i < V.size(); i++)
    {
        addEdge(V[i][0], V[i][1], G);
    }

    vis.resize(n + 1, false);
    tin.resize(n + 1, -1);
    low.resize(n + 1, -1);
    articul.resize(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            DFS(G, i, -1);
        }
    }

    if (n <= 2)
        cout << 1 << endl;
    else
        cout << (node - 1) << endl;
}