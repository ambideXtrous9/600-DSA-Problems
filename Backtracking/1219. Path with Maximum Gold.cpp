#include <bits/stdc++.h>

using namespace std;

int DFS(vector<vector<int>> &M, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || M[i][j] == 0)
        return 0;

    int temp = M[i][j];

    M[i][j] = 0;

    int ans = max({DFS(M, i, j + 1, n, m),
                   DFS(M, i, j - 1, n, m),
                   DFS(M, i + 1, j, n, m),
                   DFS(M, i - 1, j, n, m)});

    M[i][j] = temp;

    return temp + ans;
}

int getMaximumGold(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
                ans = max(ans, DFS(M, i, j, n, m));
        }
    }

    return ans;
}