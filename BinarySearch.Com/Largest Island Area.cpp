#include <bits/stdc++.h>

using namespace std;

int DFS(vector<vector<int>>& matrix,int n,int m,int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]==0)
    {
        return 0;
    }

    matrix[i][j] = 0;

   
    return 1 + DFS(matrix,n,m,i-1,j) + DFS(matrix,n,m,i+1,j) + DFS(matrix,n,m,i,j-1) +DFS(matrix,n,m,i,j+1);
}


int solve(vector<vector<int>>& matrix) 
{
    queue<pair<int,int>> Q;

    int n = matrix.size();
    int m = matrix[0].size();

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==1)
            {
                int a = DFS(matrix,n,m,i,j);
                ans = max(ans,a);
            }
        }
    }

    return ans;
    
}
