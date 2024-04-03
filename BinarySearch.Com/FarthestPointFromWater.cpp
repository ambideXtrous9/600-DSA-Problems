#include <bits/stdc++.h>

using namespace std;


// BFS
// initialize dist[n][m] = {-1};
// push all the 0s and indices in Queue
// and make those dist[i][j] = 0;
// now start BFS on all 4 directions and if dist[i][j] == -1 then update it
// dist[i][j] = dist[cur.first][cur.second] + 1
// and update max -> ans = max(ans,dist[i][j])

bool isvalid(int i, int j, int m, int n)
{
    if (i == m || j == n || j < 0 || i < 0)
        return false;
    return true;
}

int solve(vector<vector<int>> &matrix)
{
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    queue<pair<int, int>> q;

    int m = matrix.size();
    int n = matrix[0].size();

    int mx = -1;

    vector<vector<int>> dis(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        
        q.pop();
        
        for (auto &x : dir)
        {
            int a = curr.first + x[0];
            int b = curr.second + x[1];
            if (isvalid(a, b, m, n) && dis[a][b] == -1)
            {
                q.push({a, b});
                dis[a][b] = dis[curr.first][curr.second] + 1;
                mx = max(mx, dis[a][b]);
            }
        }
    }
    return mx;
}
