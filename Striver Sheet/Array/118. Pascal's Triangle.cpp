#include <bits/stdc++.h>

using namespace std;

/*
Algo:

1. if j==0 or j==i then temp[j] = 1;
2. otherwise, temp[j] = V[i-1][j-1] + V[i-1][j]  -> upper left corner + just above  
*/


vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> V;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp;

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                temp.push_back(1);
            }
            else
            {
                temp.push_back(V[i - 1][j - 1] + V[i - 1][j]);
            }
        }
        V.push_back(temp);
    }

    return V;
}