#include <bits/stdc++.h>

using namespace std;

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// Function to traverse the DAG
// and apply Dynamic Programming
// to find the longest path
void dfs(int node, vector<int> adj[], vector<int> &dp, vector<bool> &vis)
{
    // Mark as visited
    vis[node] = true;

    // Traverse for all its children
    for (auto v : adj[node])
    {

        // If not visited
        if (!vis[v])
            dfs(v, adj, dp, vis);

        // Store the max of the paths
        dp[node] = max(dp[node], 1 + dp[v]);
    }
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int n)
{
    // Dp array
    vector<int> dp(n, 0);
    vector<bool> vis(n, false);
    // Visited array to know if the node
    // has been visited previously or not

    // Call DFS for every unvisited vertex
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }

    int ans = 0;

    // Traverse and find the maximum of all dp[i]
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Driver Code
int main()
{
    int n = 5;
    vector<int> adj[n + 1];

    // Example-1
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    cout << findLongestPath(adj, n);
    return 0;
}
