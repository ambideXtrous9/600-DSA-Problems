#include <bits/stdc++.h>

using namespace std;

int eggDrop(int n, int k)
{
    if (k == 1 || k == 0)
        return k;

    if (n == 1)
        return k;

    int mini = INT_MAX, x, res;

    for (x = 1; x <= k; x++)
    {
        res = 1 +  max( eggDrop(n - 1, x - 1), // egg is broken 
                        eggDrop(n, k - x));    // egg is not broken, so check higher 

        mini = min(res, mini);
    }

    return mini;
}

int eggDropUtil(int n, int k, vector<vector<int>> &dp)
{
    if (k == 1 || k == 0)
        return k;

    if (n == 1)
        return k;

    if (dp[n][k] != -1)
        return dp[n][k];

    int mini = INT_MAX;

    for (int x = 1; x <= k; x++)
    {
        int res = 1  + max(eggDropUtil(n - 1, x - 1, dp), eggDropUtil(n, k - x, dp));

        mini = min(res, mini);
    }

    return dp[n][k] = mini;
}

int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return eggDropUtil(n, k, dp);
}

int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++) // egg
    {
        for (int j = 0; j <= k; j++)  // floor
        {
            if (j <= 1)
                dp[i][j] = j;

            else if (i <= 1)
                dp[i][j] = j;
            
            else
            {
                int mini = INT_MAX;

                for (int x = 1; x <= j; x++)
                {
                    int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);

                    mini = min(res, mini);
                }

                dp[i][j] = mini;
            }
        }
    }

    return dp[n][k];
}

int binomialCoeff(int x, int n, int k)
{
    int sum = 0, term = 1;
    
    for (int i = 1; i <= n; ++i)
    {
        term *= x - i + 1;
        term /= i;
        
        sum += term;
        
        if (sum > k)
            return sum;
    }
    return sum;
}

// Do binary search to find minimum
// number of trials in worst case.
int minTrials(int n, int k)
{
    // Initialize low and high as 1st
    // and last floors
    int low = 1, high = k;

    // Do binary search, for every mid,
    // find sum of binomial coefficients and
    // check if the sum is greater than k or not.
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (binomialCoeff(mid, n, k) < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int twoEggDrop(int k)
{
    return ceil((-1.0 + sqrt(1 + 8 * k)) / 2.0);
}

int main()
{
    int k = 100;
    cout << twoEggDrop(k);
    return 0;
}