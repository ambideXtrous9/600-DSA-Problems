#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;


void BFS(vector<int> adj[],int s,vector<bool>& visited)
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
                q.push({v,u});
            }  
        }
    }
}


void addedge(vector<int> adj[],int u,int v)
{
    adj[u].push_back((v));
    adj[v].push_back((u));
}

bool solve(int n, vector<vector<int>>& f) 
{


    vector<int> adj[n];
    vector<bool> visited(n,false);
    
    for(int i=0;i<f.size();i++)
    {
        addedge(adj,f[i][0],f[i][1]);
    }

    int count = 0;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            count++;
            BFS(adj,i,visited);
        }
    }

    if(count>1) return false;
    return true;
    
}