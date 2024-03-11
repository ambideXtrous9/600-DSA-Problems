#include <bits/stdc++.h>

using namespace std;


bool search(int i, int j, vector<vector<char>> &board, string &word, int k, int n, int m)
{
    if (k == word.size())
        return true;
    if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
        return false;
    char ch = board[i][j];
    board[i][j] = '#';
    bool op1 = search(i + 1, j, board, word, k + 1, n, m);
    bool op2 = search(i - 1, j, board, word, k + 1, n, m);
    bool op3 = search(i, j + 1, board, word, k + 1, n, m);
    bool op4 = search(i, j - 1, board, word, k + 1, n, m);   
    board[i][j] = ch; // backtracking step
    return (op1 || op2 || op3 || op4);
}

int present(vector<vector<char>> &board, string word, int n, int m)
{
    int count = 0;
    // Write your code here
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                if (search(i, j, board, word, 0, n, m))
                    count++;
            }
        }
    }
    return count;
}

int main()
{
    string needle = "BBB";
    vector<vector<char>> board = {
            {'B','B','M','B','B','B'},
            {'C','B','A','B','B','B'},
            {'I','B','G','B','B','B'},
            {'G','B','I','B','B','B'},
            {'A','B','C','B','B','B'},
            {'M','C','I','G','A','M'}};

    
    int n = board.size();
    int m = board[0].size();
 
    cout << "count: " << present(board, needle, n, m)<< endl;
    return 0;
}