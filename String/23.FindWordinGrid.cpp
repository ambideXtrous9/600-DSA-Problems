#include <bits/stdc++.h>

using namespace std;


bool search(vector<vector<char>> grid, string word, int index, int r, int c, int m, int n, int dir_r, int dir_c)
{
    if (index == word.length())
    {
        return true;
    }
    else if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != word[index])
    {
        return false;
    }
   
    return search(grid, word, index + 1, r + dir_r, c + dir_c, m, n, dir_r, dir_c);
  
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
{

    int m = grid.size();
    int n = grid[0].size();
   
    vector<vector<int>> res;
    // right, left,down,up,right-up,left-up,left-down,right-down}
    int x[] = {0, 0, 1, -1, -1, -1, 1, 1}; // change in row
    int y[] = {1, -1, 0, 0, 1, -1, -1, 1}; // change in column
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == word[0])
            {
                for (int dir = 0; dir < 8; dir++)
                {

                    if (search(grid, word, 1, i + x[dir], j + y[dir], m, n, x[dir], y[dir]))
                    {
                        vector<int> v;
                        v.push_back(i);
                        v.push_back(j);
                        res.push_back(v);
                        break;
                    }
                }
            }
        }
    }
    return res;
}