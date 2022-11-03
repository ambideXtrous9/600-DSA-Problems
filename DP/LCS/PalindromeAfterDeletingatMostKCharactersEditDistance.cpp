#include <bits/stdc++.h>

using namespace std;


// Using LCS

bool solve(string S2, int k) 
{
    string S1 = S2;

    reverse(S2.begin(),S2.end());

    int n = S1.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S1[i - 1] == S2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return (n - dp[n][n]) <=k ;

}

// Using Edit Distance


bool solve(string S2, int k) 
{
    string S1 = S2;

    reverse(S2.begin(),S2.end());

    int n = S1.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i==0) 
                dp[i][j] = j;
            
            else if(j==0) 
                dp[i][j] = i;

            else if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n]/2 <= k;
    
}