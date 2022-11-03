#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int color, vector<bool> &visited, int i, int &count, int arr[])
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (!visited[x] && arr[x] == color)
        {
            ++count;
            dfs(adj, color, visited, x, count, arr);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n + 1];
    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];

    vector<int> adj[n + 1];

    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n + 1, false);

    int res = 1;

    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            int count = 1;
            dfs(adj, arr[i], visited, i, count, arr);
            res = max(res, count);
        }
    }
    cout << res;
}

int dfs(int idx, vector<vector<int>> &graph, vector<bool> &visited, int color, vector<int> &colors)
{
    visited[idx] = true;
    int cnt = 0;

    for (auto it : graph[idx])
    {
        if (!visited[it] && colors[it] == color)
            cnt += dfs(it, graph, visited, color, colors);
    }
    return cnt + 1;
}

int maxBeer(vector<pair<int, int>> &edges, vector<int> &colors, int n, int k)
{
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
    }
    vector<bool> visited(n + 1, false);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int color = colors[i];

        if (!visited[i])
            ans = max(ans, dfs(i, graph, visited, color, colors));
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> colors(n + 1);

    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        colors[i] = c;
    }

    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++)
    {
        int s, f;
        cin >> s >> f;
        edges.push_back({s, f});
    }

    cout << maxBeer(edges, colors, n, k);
    return 0;
}
