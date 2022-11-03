#include <bits/stdc++.h>

using namespace std;

long long helper(int i, int j, vector<vector<char>> &keypad, vector<vector<vector<long long>>> &dp, int N)
{
    // boundary check
    if (i < 0 or i >= 4 or j < 0 or j >= 3 or keypad[i][j] == '*' or keypad[i][j] == '#')
        return 0;
    if (N == 1)
        return 1;
    // if answer already exists
    if (dp[i][j][N] != -1)
    {
        return dp[i][j][N];
    }
    return dp[i][j][N] = helper(i, j, keypad, dp, N - 1) + helper(i + 1, j, keypad, dp, N - 1) + helper(i - 1, j, keypad, dp, N - 1) + helper(i, j - 1, keypad, dp, N - 1) + helper(i, j + 1, keypad, dp, N - 1);
}
long long getCount(int N)
{
    // dp memoization solution
    vector<vector<char>> keypad = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};
    // using 3D dp
    vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(N + 1, -1)));
    long long count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (keypad[i][j] != '*' and keypad[i][j] != '#')
                count += helper(i, j, keypad, dp, N);
        }
    }
    return count;
}