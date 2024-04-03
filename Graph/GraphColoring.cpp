#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int greedyColoring(vector<int> adj[], int s, vector<int> &result, vector<bool> &available, int V)
{
    // Assign the first color to first vertex
    result[s] = 0;
    int cn = 0;

    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        for (auto v : adj[u])
        {
            if (result[v] != -1)
            {
                available[result[v]] = false;
            }
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
        {
            if (available[cr] == true)
                break;
        }

        result[u] = cr; // Assign the found color
        cn = max(cn, cr + 1);

        // Reset the values back to false for the next iteration
        for (auto v : adj[u])
        {
            if (result[v] != -1)
                available[result[v]] = true;
        }
    }

    return cn;
}

int main()
{
    int V = 5;
    vector<int> adj[V];

    vector<int> result(V, -1);
    vector<bool> available(V, true);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    int source = 0;

    cout << greedyColoring(adj, source, result, available, V) << endl;

    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color " << result[u] << endl;

    return 0;
}