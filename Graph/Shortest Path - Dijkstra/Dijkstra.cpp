#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;

/*

Algorithm :

1. dist[V] = {INT_MAX},  -> optional : parent[V] = {-1}

2. maintain Priority-Queue (Min Heap) instead of normal Queue

3. Start BFS from start = s node, dist[s] = 0, parent[s] = -1

4. now explore its immediate adjacents and perform edge relaxation

if(dist[u]!=INT_MAX && dist[v] > dist[u] + weight)
{
    dist[v] = dist[u] + weight;
    parent[v] = u;                 -> update the parent array
    Q.push(make_pair(dist[v],v));
}

5. at next step pick up node having least dist. -> Min Heap

*/

void addedge(vector<PI> adj[], int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void Dijkstra(int s,vector<int>& dist,vector<PI>adj[],int n)
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

}


void addedge(vector<PI> adj[],int u,int v,int weight)
{
    adj[u].push_back(make_pair(v,weight));
    adj[v].push_back(make_pair(u,weight));
}

int main()
{
    int n,m,source;
	cin >> n >> m;

	vector<PI> adj[n]; 	
    vector<int> dist(n,INT_MAX);
	
    int a,b,wt;
	for(int i = 0; i<m ; i++)
    {
		cin >> a >> b >> wt;
		addedge(adj,a,b,wt);
	}

	
	cin >> source;

    int minCost = 0;
    Dijkstra(source,dist,adj,n);

   
    cout<<"\n---------------------------\n";

    for(int i=0;i<n;i++)
    {
        cout << dist[i] <<" ";
    }

    cout<<"\n---------------------------\n";

    return 0;
}