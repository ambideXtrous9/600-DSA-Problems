#include<bits/stdc++.h>

using namespace std;


/*

Algorithm :

1. push to the satck in increasing order of their finsh time. -> DFS
max finish time at top() of the stack.

2. take Transpose of the Graph

3. from the stack top start DFS to count SCC

*/


void addEdge(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
}

void printG(vector<int> adj[],int n)
{
    cout<<"----------------------------------"<<endl;
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

// push to the satck in increasing order of their finsh time. -> DFS
// max finish time at top() of the stack.

void fillOrder(int u,vector<int> adj[],vector<bool> &visited,stack<int> &S)
{
    visited[u] = true;

    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            fillOrder(v,adj,visited,S);
        }
    }
    S.push(u);
}

void DFS(int u,vector<int> adj[],vector<bool> &visited,vector<int> &Node)
{
    visited[u] = true;
    Node.push_back(u);

    cout<<u<<" ";

    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            DFS(v,adj,visited,Node);
        }
    }
}

// take Transpose of the Graph

void getTranspose(vector<int> adj[],vector<int> revadj[],int V)
{
    for (int i = 0; i < V; i++)
    {
        for(auto v : adj[i])
        {
            revadj[v].push_back(i);
        }
    }
}

int main()
{
    int V = 5;

    vector<int> adj[V];
    stack<int> S;
    vector<int> Node;
    vector<bool> visited(V,false);

    addEdge(0,1,adj);
    addEdge(1,2,adj);
    addEdge(2,0,adj);
    addEdge(1,3,adj);
    addEdge(3,4,adj);

    printG(adj,V);

    for (int i = 0; i < V; i++)
    {
        if(!visited[i]) 
        {
            fillOrder(i,adj,visited,S);
        }
    }

    vector<int> revadj[V];

    getTranspose(adj,revadj,V);

    printG(revadj,V);

    
    visited.assign(V,false);


    cout<<"----------------SSC------------------"<<endl;
    int count = 0;

    // from the stack top start DFS to count SCC

    while (!S.empty())
    {
        int v = S.top();
        S.pop();
        if(!visited[v])
        {
            DFS(v,revadj,visited,Node);
            cout<<endl;
            count++;
        }
    }  

    cout<<"\n# OF SSC = "<<count<<endl;  
    

}
