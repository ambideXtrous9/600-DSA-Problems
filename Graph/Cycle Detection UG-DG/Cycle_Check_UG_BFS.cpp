#include<bits/stdc++.h>

using namespace std;


/*

1. Put <Node,Parent of Node> in Queue. at start : Q.append((s,-1))

2. Now explore all the Neighbourhood of u -> v = adj[u]

    a. if v is not visited, make it visited[v] = T and put in Q with parent Q.push({v,u})

    b. if v already visited, check whether it is parent of u : if not -> cycle exist

        if(parent!=v) return True

3. else Cycle does not exist.

*/

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

bool BFSUtil(vector<int> adj[],int V)
{
    vector<bool> visited(V+1,false);

    for (int i = 1; i <= V; i++)
    {
        if(visited[i]==false)
        {
            if(BFSCycle(adj,i,visited)) return true;
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
		
        bool ans = BFSUtil(adj,V);
		
        if(ans)
			cout << "1\n";
		else 
            cout << "0\n";
	}

	return 0;
}