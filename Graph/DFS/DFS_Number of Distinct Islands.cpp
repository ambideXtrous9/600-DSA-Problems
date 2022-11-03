#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> &M, int i, int j, string &S)
{
    int n = M.size();
    int m = M[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m || M[i][j] == 0)
        return;

    M[i][j] = 0;

    S += "D";
    DFS(M, i + 1, j, S);
    S += "U";
    DFS(M, i - 1, j, S);
    S += "R";
    DFS(M, i, j + 1, S);
    S += "L";
    DFS(M, i, j - 1, S);
}

int countDistinctIslands(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();

    unordered_map<string, int> mp;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                string S = "";
                DFS(M, i, j, S);
                mp[S]++;
            }
        }
    }

    return mp.size();
}