#include <bits/stdc++.h>

using namespace std;


/*

1. find the transpose
2. then reverse each row

*/

void rotate(vector<vector<int>>& M) 
    {
        
        int n = M.size();
        int m = M[0].size();
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                swap(M[i][j],M[j][i]) ;               
            }
        }
        
        for(auto &x : M) reverse(x.begin(),x.end());
        
    }