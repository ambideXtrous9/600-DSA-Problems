#include <bits/stdc++.h>

using namespace std;

bool searchWord(vector<vector<char>> &board, string word, int i, int j, int m, int n, int index)
{

    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#' || board[i][j] != word[index])
        return false;

    if (index + 1 == word.length())
    {

        return true;
    }

    char c = board[i][j];

    board[i][j] = '#';

    bool flag = searchWord(board, word, i - 1, j, m, n, index + 1) ||
                searchWord(board, word, i + 1, j, m, n, index + 1) ||
                searchWord(board, word, i, j - 1, m, n, index + 1) ||
                searchWord(board, word, i, j + 1, m, n, index + 1);

    board[i][j] = c;

    return flag;
}
bool exist(vector<vector<char>> &board, string word)
{
    if (word.length() == 0)
        return false;

    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (word[0] == board[i][j])
            {
                if (searchWord(board, word, i, j, n, m, 0))
                    return true;
            }
        }
    }

    return false;
}
