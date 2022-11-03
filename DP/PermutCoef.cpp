#include <bits/stdc++.h>

using namespace std;

int permuCoeff(int n, int k)
{
    // Base Cases/
    if (k > n)
        return 0;
    if (k == 0)
        return 1;

    // Recur
    return permuCoeff(n - 1, k - 1) + k * permuCoeff(n - 1, k);
}

int permutationCoeff(int n, int k)
{
    int P[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0)
                P[i][j] = 1;

            else
                P[i][j] = P[i - 1][j] + (j * P[i - 1][j - 1]);
        }
    }
    return P[n][k];
}

// SO
int permuCoeff(int n, int k)
{
    vector<int> C(k + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        vector<int> cur(k + 1, 0);

        // Compute next row of pascal triangle using
        // the previous row
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0)
                cur[j] = 1;
            else
                cur[j] = (C[j] + j * C[j - 1]);
        }
        C = cur;
    }
    return C[k];
}

int permutationCoeff(int n, int k)
{
    int fact[n + 1];

    // Base case
    fact[0] = 1;

    // Calculate value
    // factorials up to n
    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    // P(n,k) = n! / (n - k)!
    return fact[n] / fact[n - k];
}

int PermutationCoeff(int n, int k)
{
    int P = 1;

    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n - i);

    return P;
}