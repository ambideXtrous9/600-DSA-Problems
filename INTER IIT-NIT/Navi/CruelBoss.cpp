#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;    // number of test cases
    cin >> t;

    while(t--)
    {
        int n;   // taking input
        cin >> n;

        if(n==1 || n==2) cout<<"1"<<endl;

        else if(n==3) cout<<"2"<<endl;

        else
        {
            vector<int> dp(n+1,0);

            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;
            dp[3] = 2;

            for(int i = 4;i<=n;i++)
            {
                dp[i] = dp[i-1] + dp[i-3];
            }

            cout<<dp[n]<<endl;

        }
    }

    return 0;
}