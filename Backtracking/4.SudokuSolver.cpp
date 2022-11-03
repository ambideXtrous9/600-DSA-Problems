#include <bits/stdc++.h>

using namespace std;

#define N 9

bool isValid(vector<vector<int>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)
            {
                for (char c = 1; c <= 9; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    return true;
}

// gfg 

bool isValid(int board[N][N], int row, int col, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
    bool SolveSudoku(int board[N][N])  
    { 
        for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                for (int c = 1; c <= 9; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (SolveSudoku(board))
                            return true;
                        else
                            board[i][j] = 0;
                    }
                }

                return false;
            }
        }
    }
    return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int board[N][N]) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout<<board[i][j]<<" ";
        }
        
        // Your code here 
    }