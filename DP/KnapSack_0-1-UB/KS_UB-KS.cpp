#include <bits/stdc++.h>

using namespace std;

int knapSack(int N, int W, int val[], int wt[])
{

    if (N == 0 || W == 0)
        return 0;

    if (wt[N - 1] <= W)
        return max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt), knapSack(N - 1, W, val, wt));

    else
        return knapSack(N - 1, W, val, wt);
}

int knapSack(int N, int W, int val[], int wt[])
{

    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0) 
                dp[i][j] = 0;
            
            else if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][W];
}
