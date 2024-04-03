#include <bits/stdc++.h>
using namespace std;

// BFS Based Solution

void BFS(vector<vector<char>> M, int i, int j, vector<vector<bool>> &visited, int n, int m)
{
    queue<pair<int, int>> q;
    
    visited[i][j] = true;

    vector<int> dix = {0, 1, 0, -1, 1, 1, -1, -1};
    vector<int> diy = {1, 0, -1, 0, 1, -1, 1, -1};

    q.push({i, j});

    while (!q.empty())
    {
        auto r = q.front().first;
        auto c = q.front().second;

        q.pop();

        for (int i = 0; i < dix.size(); i++)
        {
            int u = r + dix[i];
            int v = c + diy[i];

            if (u < 0 || v < 0 || u >= n || v >= m || visited[u][v])
                continue;

            if (!visited[u][v] && M[u][v] == '1')
            {
                visited[u][v] = true;
                q.push({u, v});
            }
        }
    }
}

int numIslands(vector<vector<char>> &M)
{
    int n = M.size();
    int m = M[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && M[i][j] == '1')
            {
                BFS(M, i, j, visited, n, m);
                count++;
            }
        }
    }

    return count;
}

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int ans = numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends