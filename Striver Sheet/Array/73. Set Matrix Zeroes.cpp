#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &M)
{

    int n = M.size();
    int m = M[0].size();

    unordered_set<int> SR;
    unordered_set<int> SC;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
            {
                SR.insert(i);
                SC.insert(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (SR.find(i) != SR.end())
            {
                M[i][j] = 0;
            }
            else if (SC.find(j) != SC.end())
            {
                M[i][j] = 0;
            }
        }
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    int rowsize = matrix.size();
    int columnsize = matrix[0].size();
    
    vector<int> rowmarker(rowsize, 1);
    vector<int> columnmarker(columnsize, 1);

    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < columnsize; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowmarker[i] = 0;
                columnmarker[j] = 0;
            }
        }
    }
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < columnsize; j++)
        {
            if (rowmarker[i] == 0 or columnmarker[j] == 0)
                matrix[i][j] = 0;
        }
    }
}