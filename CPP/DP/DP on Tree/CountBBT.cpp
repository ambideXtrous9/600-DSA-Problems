#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

long long ct(int h)
{

    // if (h == 0 || h == 1) return 1;
    // or just simply
    if (h <= 1)
        return 1;

    // BF -> 0
    // ct(h-1) * ct(h-1);

    // BF -> 1
    // ct(h-1) * ct(h-2)

    // BF -> -1
    // ct(h-2) * ct(h-1)

    // or simply combine all
    // ct(h-1) * ct(h-1) + ct(h-1) * ct(h-2) * 2
    // or taking ct(h-1) common

    return ct(h - 1) * (ct(h - 1) + ct(h - 2) * 2);
}

long long dp[1005];

long long ct(int h)
{

    if (h <= 1)
        return 1;
    if (dp[h] != 0)
        return dp[h];
    return dp[h] = (ct(h - 1) * (ct(h - 1) + ct(h - 2) * 2)) % mod;
}

int mod = 1e9 + 7;
long long int countBT(int h)
{
    long long dp[h + 1];
    for (int i = 0; i <= h; i++)
    {
        if (i <= 1)
            dp[i] = 1;
        else
        {
            dp[i] = (dp[i - 1] * (dp[i - 1] + 2 * dp[i - 2])) % mod;
        }
    }

    return dp[h];
}

//SO

long long int countBT(int h)
{
    long long a = 1, b = 1, c;
    for (int i = 2; i <= h; i++)
    {
        c = b * (b + (a * 2));
        c %= mod;
        a = b, b = c;
    }
    return c;
}