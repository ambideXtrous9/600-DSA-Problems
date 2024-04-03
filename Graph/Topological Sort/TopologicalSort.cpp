#include<bits/stdc++.h>

using namespace std;

/*

Topological Sort : 

these signifies these many works can be completed roslving the dependencies

or in which order tasks should be done in order to complete all given that 

tasks do not have cyclic dependency among themselves.

*/

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    vector<int> node;
    
    for (int i = 0; i < V; i++)
    {
        for (auto v : adj[i])
        {
            indegree[v]++;
        }
    }

    queue<int> Q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            Q.push(i);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        
        Q.pop();
        
        node.push_back(u);  
        
        for (auto v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                Q.push(v);
            }
        }
    }

    return node;
    // code here
}