#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;

void Prims(int s,vector<int>& key,int parent[],vector<bool>& mSet,vector<PI>adj[],int n)
{

    priority_queue<PI,vector<PI>,greater<PI>> Q;

    key[s] = 0;
    parent[s] = -1;

    Q.push(make_pair(key[s],s));

    while(!Q.empty()) // for(int count=0;count<=V-1;count++)
    {
        int u = Q.top().second;
        int cost =  Q.top().first;
        Q.pop();

        mSet[u] = true;

        for(auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if(!mSet[v] && key[v]>weight)
            {
                key[v] = weight; 
                parent[v] = u;
                Q.push(make_pair(key[v],v));
            }
        }
    }

    //cout<<"END OF FUNCTION"<<endl;

}

void Dijkstra(int s,vector<int>& dist,vector<PI>adj[])
{

    priority_queue<PI,vector<PI>,greater<PI>> Q;

    dist[s] = 0;

    Q.push(make_pair(0,s));

    while(!Q.empty()) // for(int count=0;count<=V-1;count++)
    {
        int u = Q.top().second;
        int cost =  Q.top().first;
        Q.pop();

        for(auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if(dist[u] != INT_MAX && dist[v] > dist[u]+weight)
            {
                dist[v] = dist[u] + weight; 
                Q.push(make_pair(dist[v],v));
            }
        }
    }

    //cout<<"END OF FUNCTION"<<endl;

}




void addedge(vector<PI> adj[],int u,int v,int weight)
{
    adj[u].push_back(make_pair(v,weight));
    adj[v].push_back(make_pair(u,weight));
}

int solve(int n, vector<vector<int>>& edges) 
{
	vector<PI> adj[n+1]; 	
    vector<int> key(n+1,INT_MAX);
    int parent[n];
	
    for(int i=0;i<n;i++)
	{
		addedge(adj,edges[i][0],edges[i][1],edges[i][2]);
	}

	int minCost = 0;
	int source = edges[0][0];
    Dijkstra(source,key,adj);

	for(int i=0;i<n+1;i++)
    {
        minCost += key[i];
    }

	return minCost;
    
}