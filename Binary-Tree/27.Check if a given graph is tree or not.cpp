/*
Approach 1:

1. There is no cycle. 
2. The graph is connected.
*/

#include<bits/stdc++.h>

using namespace std;


int E = 0;
void addEdge(int u,int v,vector<int> adj[])
{
    E++;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool BFSCycle(vector<int> adj[],int s,vector<bool>& visited)
{
    queue<pair<int,int>> q;
    
    visited[s] = true;
    
    q.push({s,-1});

    while(!q.empty())
    {
        int u = q.front().first;
        
        int parent = q.front().second;
        
        q.pop();

        for (auto v : adj[u])
        {
            if(visited[v]==false)
            {
                visited[v] = true;
                q.push({v,u});
            }
            else if(parent!=v) // U's adjacent is v which is visited but not parent of u  
            {                   // then that must be visited earlier hence, there exist a cycle
                return true;
            }    
        }
    }

    return false; 
}

bool DFSCycle(vector<int> adj[],int s,int parent,vector<bool>& visited)
{
    visited[s] = true;

    for (auto v : adj[s])
    {
        if(!visited[v])
        {
            if(DFSCycle(adj,v,s,visited)) 
                return true;
        }
        else if(parent!=v) // U's adjacent is v which is visited but not prent of u  
        {                   // then that must be visited earlier hence, there exist a cycle
            return true;
        }    
    }

    return false; 
}

bool BFSUtil(vector<int> adj[],int V)
{
    vector<bool> visited(V+1,false);
    
    bool cycle = BFSCycle(adj,0,visited);
    
    for (int u = 0; u < V; u++) // check connectivity
        if (!visited[u])
           return false;

    return !cycle;
}



/*
Approach 2:

if we observe carefully the definition of tree and 
its structure we will deduce that if a graph is connected and has n – 1 edges exactly 
then the graph is a tree.
*/

bool BFSUtil(vector<int> adj[],int V)
{
    vector<bool> visited(V+1,false);
    
    bool cycle = BFSCycle(adj,0,visited);


    return !cycle && (E==V-1);
}