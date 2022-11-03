#include <bits/stdc++.h>
using namespace std;



void BFS(vector<int> adj[],int n,int s,int e)
{
    vector<bool> visited(n,false);
    vector<int> dist(n,-1);
    
    queue<int> q;

    visited[s] = true;
    dist[s] = 0;
    q.push(s);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for(auto v : adj[u])
        {
            if(!visited[v])
            {
                
                visited[v] = true;
                dist[v] = dist[u]+e;
                q.push(v);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(dist[i]!=0)
            cout<<dist[i]<<" ";
    }
}



int main() 
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        
        int n,m;
        vector<int> adj[n];
        cin>>n>>m;
        for(int j=0;j<m;j++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int s;
        cin>>s;
        s--;

        int e = 6;
    
        BFS(adj,n,s,e);
    }   
    return 0;
}
