#include <bits/stdc++.h>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do
    {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // update minimum
        min_path = min(min_path, current_pathweight);

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int TSP(int graph[][V], int s, int mask)
{
    if (mask == (1 << V) - 1)
        return graph[s][0];
    int ans = INT_MAX;
    for (int city = 0; city < V; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int cwp = graph[s][city] + TSP(graph, city, (mask | (1 << city)));
            ans = min(ans, cwp);
        }
    }
    return ans;
}

// Driver Code
int main()
{
    // matrix representation of graph
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;

    cout << TSP(graph, s, 1) << endl;

    return 0;
}