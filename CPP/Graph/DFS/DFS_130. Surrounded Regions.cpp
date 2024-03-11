#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<char>> &M, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || M[i][j] == '#' || M[i][j] == 'X')
        return;

    M[i][j] = '#';

    DFS(M, i + 1, j, n, m);
    DFS(M, i - 1, j, n, m);
    DFS(M, i, j + 1, n, m);
    DFS(M, i, j - 1, n, m);
}

void solve(vector<vector<char>> &board)
{

    int n = board.size();
    int m = board[0].size();

    // first row
    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
        {
            DFS(board, 0, i, n, m);
        }
    }
    // last row
    for (int i = 0; i < m; i++)
    {
        if (board[n - 1][i] == 'O')
        {
            DFS(board, n - 1, i, n, m);
        }
    }
    // first col
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
        {
            DFS(board, i, 0, n, m);
        }
    }
    // last col
    for (int i = 0; i < n; i++)
    {
        if (board[i][m - 1] == 'O')
        {
            DFS(board, i, m - 1, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}