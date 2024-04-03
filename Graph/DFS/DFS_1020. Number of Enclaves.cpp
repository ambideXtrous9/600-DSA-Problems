#include <bits/stdc++.h>

using namespace std;

// 130. Surrounded Regions

void DFS(vector<vector<int>> &M, int i, int j)
{
    int n = M.size();
    int m = M[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m || M[i][j] == 0)
        return;

    M[i][j] = 0;

    DFS(M, i + 1, j);
    DFS(M, i - 1, j);
    DFS(M, i, j + 1);
    DFS(M, i, j - 1);
}

int numEnclaves(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();

    for (int i = 0; i < m; i++)
    {
        if (M[0][i] == 1)
            DFS(M, 0, i);
    }

    for (int i = 0; i < m; i++)
    {
        if (M[n - 1][i] == 1)
            DFS(M, n - 1, i);
    }

    for (int i = 0; i < n; i++)
    {
        if (M[i][0] == 1)
            DFS(M, i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        if (M[i][m - 1] == 1)
            DFS(M, i, m - 1);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
                ans++;
        }
    }

    return ans;
}