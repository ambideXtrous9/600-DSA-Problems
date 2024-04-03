#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PI;

/*

Algorithm :

1. dist[V] = {INT_MAX}, parent[V] = {-1}, mSet[V] = false

2. maintain Priority-Queue (Min Heap) instead of normal Queue

3. Start BFS from start = s node, dist[s] = 0, parent[s] = -1

4. pop() from front and make it include in mSet[u] = true

5. now explore its immediate adjacents that are not yet included in mSet[] and
update its distance,

if(!mSet[v] && key[v]>weight)
{
    key[v] = weight;
    parent[v] = u;                 -> update the parent array
    Q.push(make_pair(key[v],v));
}

6. at next step pick up node having least dist. -> Min Heap


*/

void addedge(vector<PI> adj[], int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void Prims(int s, vector<int> &key, int parent[], vector<bool> &mSet, vector<PI> adj[], int n)
{
    priority_queue<PI, vector<PI>, greater<PI>> Q;

    key[s] = 0;
    parent[s] = -1;

    Q.push({key[s], s});

    while (!Q.empty()) // for(int count=0;count<=V-1;count++)
    {
        int u = Q.top().second;
        int cost = Q.top().first;
        Q.pop();

        mSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (!mSet[v] && key[v] > weight)
            {
                key[v] = weight;
                parent[v] = u;
                Q.push({key[v], v});
            }
        }
    }
}

int main()
{
    int n, m, source;
    cin >> n >> m;

    vector<PI> adj[n];

    vector<int> key(n, INT_MAX);
    vector<bool> mSet(n, false);

    int parent[n];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        addedge(adj, a, b, wt);
    }

    cin >> source;

    int minCost = 0;
    Prims(source, key, parent, mSet, adj, n);

    cout << "\n---------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }

    cout << "\n---------------------------\n";

    for (int i = 0; i < n; i++)
    {
        minCost += key[i];
    }
    cout << "\nMIN COST = " << minCost << endl;

    return 0;
}

typedef pair<int, int> p;

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> mset(V, false);
    vector<int> dist(V, INT_MAX);

    priority_queue<p, vector<p>, greater<p>> Q;

    mset[0] = 1;
    dist[0] = 0;

    Q.push({0, 0});

    int ans = 0;

    while (!Q.empty())
    {
        int cost = Q.top().first;
        int u = Q.top().second;
        Q.pop();

        mset[u] = 1;

        for (auto x : adj[u])
        {
            int v = x[0];
            int w = x[1];

            if (!mset[v] && dist[v] > w)
            {
                dist[v] = w;

                Q.push({dist[v], v});
            }
        }
    }

    for (auto x : dist)
        ans += x;

    return ans;
}