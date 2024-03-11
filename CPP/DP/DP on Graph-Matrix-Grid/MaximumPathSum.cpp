#include <bits/stdc++.h>

using namespace std;

int MP(int r, int c, int N, vector<vector<int>> A)
{
    if (r == N - 1)
        return A[r][c];

    int D = A[r][c] + MP(r + 1, c, N, A);

    int LDD = 0;
    if (c - 1 >= 0)
        LDD = A[r][c] + MP(r + 1, c - 1, N, A);
    else
        LDD = INT_MIN;

    int RDD = 0;

    if (c + 1 < N)
        RDD = A[r][c] + MP(r + 1, c + 1, N, A);
    else
        RDD = INT_MIN;

    return max(D, max(LDD, RDD));
}

int MP(int r, int c, int N, vector<vector<int>> A, vector<vector<int>> &dp)
{
    if (r == N - 1)
        return A[r][c];

    if (dp[r][c] != -1)
        return dp[r][c];

    int D = A[r][c] + MP(r + 1, c, N, A, dp);

    int LDD = 0;
    if (c - 1 >= 0)
        LDD = A[r][c] + MP(r + 1, c - 1, N, A, dp);
    else
        LDD = INT_MIN;

    int RDD = 0;

    if (c + 1 < N)
        RDD = A[r][c] + MP(r + 1, c + 1, N, A, dp);
    else
        RDD = INT_MIN;

    return dp[r][c] = max(D, max(LDD, RDD));
}

int maximumPath(int N, vector<vector<int>> Matrix)
{
    int res = INT_MIN;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    for (int i = 0; i < N; i++)
    {
        res = max(res, MP(0, i, N, Matrix, dp));
    }

    return res;
}

int maximumPath(int N, vector<vector<int>> A)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int r = N - 1; r >= 0; r--)
    {
        for (int c = N - 1; c >= 0; c--)
        {
            if (r == N - 1)
                dp[r][c] = A[r][c];

            else
            {
                int D = A[r][c] + dp[r + 1][c];

                int LDD = LDD = INT_MIN;
                if (c - 1 >= 0)
                    LDD = A[r][c] + dp[r + 1][c - 1];

                int RDD = INT_MIN;
                if (c + 1 < N)
                    RDD = A[r][c] + dp[r + 1][c + 1];

                dp[r][c] = max(D, max(LDD, RDD));
            }
        }
    }

    int res = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        res = max(res, dp[0][i]);
    }
    return res;
}

int maximumPath(int N, vector<vector<int>> A)
{
    vector<int> prev(N + 1, 0);
    vector<int> cur(N + 1, 0);

    for (int r = N - 1; r >= 0; r--)
    {
        for (int c = N - 1; c >= 0; c--)
        {
            if (r == N - 1)
                cur[c] = A[r][c];

            else
            {
                int D = A[r][c] + prev[c];

                int LDD = 0;
                if (c - 1 >= 0)
                    LDD = A[r][c] + prev[c - 1];
                else
                    LDD = INT_MIN;

                int RDD = 0;

                if (c + 1 < N)
                    RDD = A[r][c] + prev[c + 1];
                else
                    RDD = INT_MIN;

                cur[c] = max(D, max(LDD, RDD));
            }
        }

        prev = cur;
    }

    int res = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        res = max(res, prev[i]);
    }
    return res;
}