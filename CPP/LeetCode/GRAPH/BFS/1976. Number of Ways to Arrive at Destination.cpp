#include <bits/stdc++.h>

using namespace std;

/*
Complexity

Time: O(M * logN + N), where M <= N*(N-1)/2 is number of roads, N <= 200 is number of intersections.
Space: O(N + M)
Question & Answer

** Should I remove this line if dist[u] < d: continue # Skip if d is not updated to latest version!?

If you remove that line, the time complexity becomes O(V^3 * logV), 
which can run pass all the testcases since V <= 200.
But if you keep that line, the time complexity reduces to O(V^2 * logV).
Explain: Other neightbors may visit node u multiple times (up to O(V) times) 
and push node u to the minHeap. In the worst case, node u will pop and process O(V) times, 
each time it takes O(V) to visit neighbors, there is up to V nodes like node u. 
So total time complexity is O(V^3 * logV).
*/

typedef pair<long long, long long> PI;

int mod = 1e9 + 7;

void addEdge(long long u, long long v, long long w, vector<PI> adj[])
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int countPaths(int n, vector<vector<int>> &edges)
{
    priority_queue<PI, vector<PI>, greater<PI>> Q;

    vector<PI> adj[n];

    for (int i = 0; i < edges.size(); i++)
    {
        addEdge(edges[i][0], edges[i][1], edges[i][2], adj);
    }

    vector<long long> dist(n, LONG_MAX);
    vector<long long> path(n, 0);

    Q.push({0, 0});

    dist[0] = 0;
    path[0] = 1;

    while (!Q.empty())
    {

        long long val = Q.top().first;
        int u = Q.top().second;

        Q.pop();

        if (val > dist[u])   // explained above
            continue;

        for (auto x : adj[u])
        {
            long long dis = x.second;
            int v = x.first;

            if (dist[v] > dist[u] + dis)
            {
                dist[v] = dist[u] + dis;

                Q.push({dist[v], v});

                path[v] = path[u] % mod;
            }
            else if (dist[v] == dist[u] + dis)
            {
                path[v] += path[u];
                path[v] %= mod;
            }
        }
    }

    for (auto x : path)
        cout << x << " ";

    return path[n - 1];
}