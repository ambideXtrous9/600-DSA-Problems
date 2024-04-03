#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;

void addedge(vector<PI> adj[],int u,int v,int weight,bool undic = true)
{
    adj[u].push_back(make_pair(v,weight));
    if(undic) adj[v].push_back(make_pair(u,weight));
}

void printG(vector<PI> adj[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" -> ";
        for(auto x : adj[i])
        {
            cout<< x.first<<"--"<<x.second<<"--"<<" ";
        }
        cout<<"\n";
    }
    
}

int main()
{
    int n,m,source;
	cin >> n >> m;

	vector<PI> adj[n]; 	
    int parent[n];
	
    int a,b,wt;
	for(int i = 0; i<m ; i++)
    {
		cin >> a >> b >> wt;
		addedge(adj,a,b,wt,false);
	}

    printG(adj,n);

    return 0;

}