#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &image, int i, int j, int val, int newColor)
{
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor || image[i][j] != val)
    {
        return;
    }

    image[i][j] = newColor;

    dfs(image, i - 1, j, val, newColor);
    dfs(image, i + 1, j, val, newColor);
    dfs(image, i, j - 1, val, newColor);
    dfs(image, i, j + 1, val, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int val = image[sr][sc];
    dfs(image, sr, sc, val, newColor);
    return image;
}

void BFS(vector<vector<int>> &M, int i, int j, int col, int prev)
{
    int n = M.size();
    int m = M[0].size();

    queue<pair<int, int>> Q;

    Q.push({i, j});

    M[i][j] = col;

    vector<int> dir = {0, 1, 0, -1, 0};

    while (!Q.empty())
    {
        auto [u, v] = Q.front();
        Q.pop();

        for (int k = 0; k < 4; k++)
        {
            i = u + dir[k];
            j = v + dir[k + 1];

            if (i < 0 || j < 0 || i >= n || j >= m || M[i][j] == col || M[i][j] != prev)
                continue;

            M[i][j] = col;
            Q.push({i, j});
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int prev = image[sr][sc];
    BFS(image, sr, sc, color, prev);

    return image;
}