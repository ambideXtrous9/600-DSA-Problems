#include <bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = numCourses;

    vector<int> adj[n];
    vector<int> indegree(n, 0);

    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }

    queue<int> Q;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
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

        for (auto v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
            {
                Q.push(v);
            }
        }
    }

    return count == n;
}