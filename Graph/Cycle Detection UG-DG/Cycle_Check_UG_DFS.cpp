#include<bits/stdc++.h>

using namespace std;

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

bool DFSUtil(vector<int> adj[],int V)
{
    vector<bool> visited(V+1,false);

    for (int i = 1; i <= V; i++)
    {
        if(visited[i]==false)
        {
            if(DFSCycle(adj,i,-1,visited)) return true;
        }
    }

    return false;
}

int main()
{

	int tc;
	cin >> tc;

	while(tc--)
    {
		int V, E;
		cin >> V >> E;
		
        vector<int>adj[V];
		
        for(int i = 0; i < E; i++)
        {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
        bool ans = DFSUtil(adj,V);
		
        if(ans)
			cout << "1\n";
		else 
            cout << "0\n";
	}

	return 0;
}