#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;


void addEdge(int u,int v,int weight,vector<PI> adj[])
{
    adj[u].push_back(make_pair(v,weight));
}

void fillOrder(int u,vector<PI> adj[],vector<bool> &visited,stack<int> &S)
{
    visited[u] = true;

    for(auto X : adj[u])
    {
        int v = X.first;
        
        if(!visited[v])
        {
            fillOrder(v,adj,visited,S);
        }
    }
    S.push(u);
}

void LongestPath(int s, stack<int> &S, vector<PI> adj[], vector<bool> &visited, vector<int> &dist)
{
    dist[s] = 0;
    while (!S.empty())
    {
        int u = S.top();
        S.pop();

        for (auto X : adj[u])
        {
            int v = X.first;
            int w = X.second;

            if (dist[u]!=INT_MIN && dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main()
{
    int V = 6;

    vector<PI> adj[V];
    stack<int> S;
    vector<int> Node;
    vector<bool> visited(V,false);
    vector<int> dist(V,INT_MIN);

    addEdge(0, 1, 5,adj);
    addEdge(0, 2, 3,adj);
    addEdge(1, 3, 6,adj);
    addEdge(1, 2, 2,adj);
    addEdge(2, 4, 4,adj);
    addEdge(2, 5, 2,adj);
    addEdge(2, 3, 7,adj);
    addEdge(3, 5, 1,adj);
    addEdge(3, 4, -1,adj);
    addEdge(4, 5, -2,adj);

    int source = 1;


    for (int i = 0; i < V; i++)
    {
        if(!visited[i]) 
        {
            fillOrder(i,adj,visited,S);
        }
    }

    LongestPath(source,S,adj,visited,dist);

    cout<<"\n---------------------------\n";

    for(int i=0;i<V;i++)
    {
        cout << dist[i] <<" ";
    }
    cout<<"\n";
    

}
