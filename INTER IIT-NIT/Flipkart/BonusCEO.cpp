#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int par, vector<bool> &visited, vector<vector<int>> &adj)
{
    if (visited[i] == true)
    {
        visited[par] = true;
        return;
    }
    for (int j : adj[i])
    {
        dfs(j, i, visited, adj);
    }
}

void solve()
{
    int n, p, projects, temp;
    cin >> n >> p;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        adj[i].push_back(temp);
    }

    vector<bool> visited(n + 1, false);
    
    visited[0] = true;

    for (int i = 0; i < p; i++)
    {
        cin >> projects;
        dfs(projects, projects, visited, adj);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
            cout << i << " ";
    }
}

int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}