#include <bits/stdc++.h>

using namespace std;


/*
shrotest distance from S node to 
D node avoiding negative weight cycle

Algorithm:

1. concept : if graph has n nodes, then shortest path in the G, 
will never contain more than (n-1) edges

2. So relax every edge (n-1) times.

3. initialize dist[V] = INT_MAX, and dist[s] = 0;

*/

int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{

    vector<int> dis(n, INT_MAX);

    dis[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto x : edges)
        {
            if (dis[x[0]] != INT_MAX && dis[x[1]] > dis[x[0]] + x[2])
            {
                dis[x[1]] = dis[x[0]] + x[2];
            }
        }
    }

    for (auto x : edges)
    {
        if (dis[x[0]] != INT_MAX && dis[x[1]] > dis[x[0]] + x[2])
        {
            return true;
        }
    }

    return false;
}

struct Node
{
    int start;
    int end;
    int weight;
    Node(int s, int e, int w)
    {
        start = s;
        end = e;
        weight = w;
    }
};

void addEdge(int u, int v, int w, vector<Node> &Edges)
{
    Edges.push_back((Node(u, v, w)));
}

bool BellmanFord(vector<Node> &Edges, vector<int> &dist, int V, int E, int s)
{
    dist[s] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = Edges[j].start;
            int v = Edges[j].end;
            int w = Edges[j].weight;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) // same as dijkstra
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        int u = Edges[j].start;
        int v = Edges[j].end;
        int w = Edges[j].weight;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
        {
            return true;
            dist[v] = dist[u] + w;
        }
    }
    return false;
}

int main()
{
    int source = 0;

    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph

    vector<Node> Edges;
    vector<int> dist(V, INT_MAX);

    // add edge 0-1 (or A-B in above figure)
    Edges.push_back(Node(0, 1, -1));

    // add edge 0-2 (or A-C in above figure)
    Edges.push_back(Node(0, 2, 4));

    // add edge 1-2 (or B-C in above figure)
    Edges.push_back(Node(1, 2, 3));

    // add edge 1-3 (or B-D in above figure)
    Edges.push_back(Node(1, 3, 2));

    // add edge 1-4 (or B-E in above figure)
    Edges.push_back(Node(1, 4, 2));

    // add edge 3-2 (or D-C in above figure)
    Edges.push_back(Node(3, 2, 5));

    // add edge 3-1 (or D-B in above figure)
    Edges.push_back(Node(3, 1, 1));

    // add edge 4-3 (or E-D in above figure)
    Edges.push_back(Node(4, 3, -3));

    int minCost = 0;
    BellmanFord(Edges, dist, V, E, source);

    cout << "\n---------------------------\n";

    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n---------------------------\n";

    return 0;
}