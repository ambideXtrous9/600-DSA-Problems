#include<bits/stdc++.h>
using namespace std;

typedef  pair<int, int> PI;

void addEdge(int u, int v, int w,vector< pair<int, PI> > &edges)
{
    edges.push_back({w, {u, v}});
}

int findPar(int u, vector<int> &parent) 
{
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) 
{
    u = findPar(u, parent);
    v = findPar(v, parent);
   
    if(rank[u] < rank[v]) 
    {
    	parent[u] = v;
    }
   
    else if(rank[v] < rank[u]) 
    {
    	parent[v] = u; 
    }
   
    else 
    {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main()
{
    vector< pair<int, PI> > edges;

	int V = 9, E = 14;
  
    //  making above shown graph
    addEdge(0, 1, 4,edges);
    addEdge(0, 7, 8,edges);
    addEdge(1, 2, 8,edges);
    addEdge(1, 7, 11,edges);
    addEdge(2, 3, 7,edges);
    addEdge(2, 8, 2,edges);
    addEdge(2, 5, 4,edges);
    addEdge(3, 4, 9,edges);
    addEdge(3, 5, 14,edges);
    addEdge(4, 5, 10,edges);
    addEdge(5, 6, 2,edges);
    addEdge(6, 7, 1,edges);
    addEdge(6, 8, 6,edges);
    addEdge(7, 8, 7,edges);
	
    sort(edges.begin(), edges.end()); 
	
	vector<int> parent(V);

	for(int i = 0;i<V;i++)
    {
        parent[i] = i;
    } 
	     
	vector<int> rank(V, 0); 
	
	int cost = 0;
	vector< pair<int, PI> > MST;

	for(auto it : edges) 
    {
        int u = it.second.first;
        int v = it.second.second;

	    if(findPar(u, parent) != findPar(v, parent)) 
        {
	        cost += it.first; 
	        MST.push_back(make_pair(it.first,make_pair(u,v))); 
	        unionn(u, v, parent, rank); 
	    }
	}

	cout<< cost << endl;
	
    for(auto it : MST) 
        cout << "W = "<<it.first <<" NODE = "<< it.second.first<<" - " << it.second.second << endl; 
	return 0;
}