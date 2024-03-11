#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int solve(string S)
{
    int nq = 0;

    int n = S.length();

    for (auto c : S)
        if (c == '?')
            nq++;

    vector<int> dp0(n, 0); // dp0[i] -> # of 'ab' till idx i with 0 '?' involved
    vector<int> dp1(n, 0); // dp1[i] -> # of 'ab' till idx i with 1 '?' involved
    vector<int> dp2(n, 0); // dp2[i] -> # of 'ab' till idx i with 2 '?' involved

    vector<int> dp_0(n, 0);
    vector<int> dp_1(n, 0);
    vector<int> dp_2(n, 0);

    int numa = 0;
    int numq = 0;

    for (int i = 0; i < n; i++)
    {
        if (S[i] == 'a' || S[i] == 'c') // if a and c it can not end with b, so all 0
        {
            dp0[i] = 0;
            dp1[i] = 0;
            dp2[i] = 0;
        }
        else if (S[i] == 'b')
        {
            dp0[i] = numa;
            dp1[i] = numq;
            dp2[i] = 0;
        }
        else
        {
            dp0[i] = 0;
            dp1[i] = numa;
            dp2[i] = numq;
        }

        dp_0[i] = dp0[i];
        dp_1[i] = dp1[i];
        dp_2[i] = dp2[i];

        if (i > 0)
        {
            dp_0[i] = dp_0[i] + dp_0[i - 1];
            dp_1[i] = dp_1[i] + dp_1[i - 1];
            dp_2[i] = dp_2[i] + dp_2[i - 1];
        }

        if (S[i] == 'a')
            numa++;
        if (S[i] == '?')
            numq++;
    }

    vector<int> dp(n, 0);
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (S[i] == 'a' || S[i] == 'b')
            dp[i] = 0;

        else if (S[i] == 'c')
        {
            dp[i] = dp[i] + dp_0[i - 1] * pow(3, nq);

            if (nq > 0)
                dp[i] = dp[i] + dp_1[i - 1] * pow(3, nq - 1);

            if (nq > 1)
                dp[i] = dp[i] + dp_2[i - 1] * pow(3, nq - 2);
        }
        else
        {
            dp[i] = dp[i] + dp_0[i - 1] * pow(3, nq - 1);

            if (nq > 0)
                dp[i] = dp[i] + dp_1[i - 1] * pow(3, nq - 2);

            if (nq > 1)
                dp[i] = dp[i] + dp_2[i - 1] * pow(3, nq - 3);
        }

        ans += dp[i];
    }

    return ans;
}