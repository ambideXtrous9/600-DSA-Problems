#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;

void addedge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printG(vector<int> adj[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" -> ";
        for(auto x : adj[i])
        {
            cout<< x <<" ";
        }
        cout<<"\n";
    }
    
}

int main()
{
    int n=4;

	vector<int> adj[n]; 	

	addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,1);

    printG(adj,n);

    return 0;

}