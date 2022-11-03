#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;    // number of test cases
    cin >> t;

    while(t--)
    {
        int k,n;

        cin>>k>>n;

        vector<int> arr(n);

        for(int i = 0;i<n;i++) cin>>arr[i];

        int dp[n+1][2][k+1];

        memset(dp,0,sizeof(dp));

        for(int i = n-1;i>=0;i--)
        {
            for(int flag = 1;flag >=0; flag--)
            {
                for(int j = 1;j<=k;j++)
                {
                    int cost = dp[i+1][flag][j];

                    if(flag && j)
                    {
                        cost = max(cost,-arr[i] + dp[i+1][!flag][j]);
                    }
                    else
                    {
                        cost = max(cost,arr[i] + dp[i+1][!flag][j-1]);
                    }

                    dp[i][flag][j] = cost;
                }
            }
        }

        return dp[0][1][k];

    }
    
}