#include <bits/stdc++.h>

using namespace std;

int BFS(vector<vector<int>> &G, int i, int j, int n, int m, int k, vector<vector<int>> &Stores)
{
    queue<vector<int>> Q;

    vector<vector<int>> visited(n + 1, vector<int>(m + 1, false));

    Q.push({i, j, k});

    vector<int> dir = {0, 1, 0, -1, 0};

    while (!Q.empty())
    {
        auto v = Q.front();
        Q.pop();

        i = v[0];
        j = v[1];
        k = v[2];

        visited[i][j] = true;
        Stores[i][j] += 1;

        k -= 1;

        for (int t = 0; t < 4; t++)
        {
            i = i + dir[t];
            j = j + dir[t + 1];

            if (i < 0 || i >= n || j < 0 || j >= m || k < 0 || visited[i][j])
                continue;

            Q.push({i, j, k});
        }
    }
}

int StoreCount(vector<vector<int>> &M, int k)
{
    int n = M.size();
    int m = M[0].size();

    int house = 0;

    vector<vector<int>> count(n + 1, vector<int>(m + 1, 0));

    unordered_map<int, unordered_map<int, int>> HouseCoord;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                house += 1;
                HouseCoord[i][j] = 1;
                BFS(M, i, j, n, m, k, count);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0 && count[i][j] == house)
                res++;
        }
    }

    return res;
}