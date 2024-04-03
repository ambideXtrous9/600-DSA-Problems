#include <bits/stdc++.h>

using namespace std;

void Bridges(int s,int p,vector<int> adj[],vector<bool> &visited,vector<int> &tin,vector<int> &low,int &timer)
{
    visited[s] = true;

    tin[s] = low[s] = timer++;

    for(auto v : adj[s])
    {
        if(v==p) continue;

        if(!visited[v])
        {
            Bridges(v,s,adj,visited,tin,low,timer);
            
            low[s] = min(low[v],low[s]);
            
            if(low[v]>tin[s])
            {
                cout<<s<<"--->"<<v<<endl;
            }
        }
        else
        {
            low[s] = min(low[s],tin[v]);
        }
    }

}