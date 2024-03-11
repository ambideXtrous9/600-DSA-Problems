#include <bits/stdc++.h>

using namespace std;

void addEdge(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = numCourses;

    vector<int> adj[n];

    for (int i = 0; i < prerequisites.size(); i++)
    {
        addEdge(prerequisites[i][1],prerequisites[i][0],adj);
    }

    vector<int> indegree(n,0);

    for(int i=0;i<n;i++)
    {
        for(auto v : adj[i])
        {
            indegree[v]++;
        }
    }

    queue<int> Q;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            Q.push(i);
        }
    }

    int count = 0;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        count++;

        for(auto v : adj[u])
        {
            indegree[v]--;

            if(indegree[v]==0)
            {
                Q.push(v);
            }
        }
    }
    
    return count==n;
}