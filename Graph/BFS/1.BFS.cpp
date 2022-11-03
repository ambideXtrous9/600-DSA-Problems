#include <bits/stdc++.h>

using namespace std;

void addEdge(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> M[],int s,vector<bool> &visited)
{
    queue<int> Q;
    visited[s] = true;
    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        // print Node here

        for(auto v : M[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                Q.push(v);
            }
            
        }
    }
}

int solve(vector<vector<int>>& F) 
{

    int n = F.size();

    vector<int> adj[n];
    vector<bool> visited(n,false);
    
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<F[i].size();j++)
            addEdge(i,F[i][j],adj);
    }

    int count = 0;

    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            count++;
            BFS(adj,i,visited);
        }

    }

    return count;
    
}