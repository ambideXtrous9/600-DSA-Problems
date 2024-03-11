#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

// Recursion
int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    // Recur
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

//DP

int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;

    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously
            // stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

// SO
int binomialCoeff(int n, int k)
{
    vector<int> C(k + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        vector<int> cur(k + 1, 0);

        // Compute next row of pascal triangle using
        // the previous row
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || i == j)
                cur[j] = 1;
            else
                cur[j] = (C[j] + C[j - 1]) % mod;
        }
        C = cur;
    }
    return C[k];
}