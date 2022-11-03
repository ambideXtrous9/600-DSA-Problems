#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int solve(int i, int j, int a[])
{

    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int x = a[i] + min(solve(i + 2, j, a), solve(i + 1, j - 1, a));
    int y = a[j] + min(solve(i, j - 2, a), solve(i + 1, j - 1, a));

    return dp[i][j] = max(x, y);
}

long long maximumAmount(int arr[], int n)
{
    // Your code here
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    return solve(0, n - 1, arr);
}

// 877. Stone Game

int dp[501][501];

int Game(vector<int> &piles, int i, int j)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int x = piles[i] + min(Game(piles, i + 2, j), Game(piles, i + 1, j - 1));

    int y = piles[j] + min(Game(piles, i + 1, j - 1), Game(piles, i, j - 2));

    return dp[i][j] = max(x, y);
}

bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    int sum = 0;

    memset(dp, -1, sizeof(dp));

    for (auto x : piles)
        sum += x;
    int res = Game(piles, 0, n - 1);

    return res > (sum / 2);
}

int dp[501][501] = {};

int takeStone(bool alex, int l, int h, vector<int> &piles)
{
    // base cases
    if (l > h)
        return 0;
    if (l == h)
        return piles[l];

    // return precalculated result
    if (dp[l][h] != -1)
        return dp[l][h];

    // alex's turn, alex can take either piles[l] or piles[h] so we add them with the recursion call as
    // piles[l]+takeStone(l+1,h) or piles[h]+takeStone(l,h-1) and get the max value betweeen them
    // for getting the game result as alex always tries to maximize his pile count
    if (alex)
        dp[l][h] = max(piles[l] + takeStone(!alex, l + 1, h, piles), piles[h] + takeStone(!alex, l, h - 1, piles));

    // lee's turn, choice for lee is same as alex, only differece is that lee wants to maximize his
    // game result by minimizing alex's result and so we return the min value between those two choices
    // also to get game result we deduct piles[l] or piles[h] with recursion calls
    else
        dp[l][h] = min(-piles[l] + takeStone(!alex, l + 1, h, piles), -piles[h] + takeStone(!alex, l, h - 1, piles));

    return dp[l][h];
}

bool stoneGame(vector<int> &piles)
{

    int n = piles.size();
    memset(dp, -1, sizeof(dp));

    // alex turn = true, lee turn = false
    // Game result = max piles count of Alex - max piles count of Lee
    // If result > 0 then Alex wins
    return takeStone(true, 0, n - 1, piles) > 0;
}