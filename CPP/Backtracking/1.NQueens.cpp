#include <bits/stdc++.h>

using namespace std;

bool isSafe1(int row, int col, vector<string> board, int n)
{
    // check upper element
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &V, vector<vector<int>> &A)
{
    if (col == n)
    {
        A.push_back(V);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            V.push_back(row + 1);
            solve(col + 1, board, ans, n, V, A);
            board[row][col] = '.';
            V.pop_back();
        }
    }
}
vector<vector<int>> nQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    vector<int> V;
    vector<vector<int>> A;
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n, V, A);
    return A;
}