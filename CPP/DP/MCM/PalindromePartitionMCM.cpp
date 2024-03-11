#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start += 1;
        end -= 1;
    }
    return true;
}

int solve(string &s, int start, int end, vector<vector<int>> &dp)
{

    if (start >= end)
        return 0;

    if (isPalindrome(s, start, end) == true)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int ans = INT_MAX;

    for (int ctr = start; ctr < end; ctr++)
    {

        if (isPalindrome(s, start, ctr) == false)
            continue;

        int tempAns = 1 + solve(s, start, ctr, dp) + solve(s, ctr + 1, end, dp);

        if (tempAns < ans)
            ans = tempAns;
    }

    return dp[start][end] = ans;
}

int minCut(string s)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
    return solve(s, 0, s.length() - 1, dp);
}

int PP(string &str, int i, int n)
{
    if (i == n)
        return 0;

    int res = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(str, i, j))
        {
            int cost = 1 + PP(str, j + 1, n);
            res = min(res, cost);
        }
    }

    return res;
}

int palindromicPartition(string str)
{
    int n = str.length();

    return PP(str, 0, n) - 1;
}

int PP(string &str, int i, int n, vector<int> &dp)
{
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int res = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(str, i, j))
        {
            int cost = 1 + PP(str, j + 1, n, dp);
            res = min(res, cost);
        }
    }

    return dp[i] = res;
}

int palindromicPartition(string str)
{
    int n = str.length();

    vector<int> dp(n, -1);
    return PP(str, 0, n, dp) - 1;
}

int PP(string str)
{
    int n = str.length();

    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int res = INT_MAX;

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(str, i, j))
            {
                int cost = 1 + dp[j + 1];
                res = min(res, cost);
            }
        }

        dp[i] = res;
    }
    return dp[0] - 1;
}

//------------------------------------------------------------------------------------------------------------

int PPMCM(string str, vector<vector<int>> &dp, int i, int j)
{
    if (i >= j)
        return 0;

    if (isPalindrome(str, i - 1, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int res = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp = 1 + PPMCM(str, dp, i, k) + PPMCM(str, dp, k + 1, j);
        res = min(res, temp);
    }
    return dp[i][j] = res;
}

int palindromicPartition(string str)
{

    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return PPMCM(str, dp, 1, n - 1);
}

//============================================================================
int dp[1001][1001];
int solve(string s, int i, int j)
{
    if (i >= j)
        return dp[i][j] = 0;

    if (isPalindrome(s, i, j) == true)
        return dp[i][j] = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        //  int temp=solve(s,i,k)+solve(s,k+1,j)+1;
        int right, left;
        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = solve(s, i, k);
        }
        dp[i][k] = left;

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = solve(s, k + 1, j);
        dp[k + 1][j] = right;

        int temp = 1 + left + right;
        mn = min(temp, mn);
    }
    return dp[i][j] = mn;
}

int palindromicPartition(string str)
{
    // code here
    memset(dp, -1, sizeof(dp));
    int n = str.length();
    return solve(str, 0, n - 1);
}