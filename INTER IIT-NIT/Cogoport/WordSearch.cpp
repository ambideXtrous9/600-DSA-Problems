#include <bits/stdc++.h>

using namespace std;


static void searchWord(vector<vector<char>> board, string word, int &count, int i, int j, int m, int n, int index)
{

    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#' || board[i][j] != word[index])
        return;

    if (index + 1 == word.length())
    {
        count++;
        return;
    }

    char c = board[i][j];

    board[i][j] = '#';

    searchWord(board, word, count, i - 1, j, m, n, index + 1);
    searchWord(board, word, count, i + 1, j, m, n, index + 1);
    searchWord(board, word, count, i, j - 1, m, n, index + 1);
    searchWord(board, word, count, i, j + 1, m, n, index + 1);

    board[i][j] = c;
}