#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int DFS(vector<vector<int>> &M, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return 1e9;

    if (i == n - 1)
        return M[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int LD = DFS(M, i + 1, j - 1, n, m);
    int RD = DFS(M, i + 1, j + 1, n, m);
    int D = DFS(M, i + 1, j, n, m);

    return dp[i][j] = M[i][j] + min({LD, RD, D});
}

int main()
{

    int n, m;
    cin >> n >> m;

    int health;

    cin >> health;

    vector<vector<int>> M(n, vector<int>(m, 0));

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    int ans = INT_MAX;

    for (int j = 0; j < m; j++)
    {
        int res = DFS(M, 0, j, n, m);
        ans = min(ans, res);
    }

    cout << "Decrease Health = " << ans << endl;

    cout << "Final Health = " << (health - ans) << endl;

    return 0;
}