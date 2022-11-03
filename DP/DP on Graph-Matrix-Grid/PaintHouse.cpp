#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost of
// coloring the houses such that no two
// adjacent houses has the same color

int dp[501][501];
int minCost(vector<vector<int>> &costs, int n, int m, int col)
{
    if (n <= 0)
        return 0;

    if (dp[n][col] != -1)
        return dp[n][col];

    int temp_cost = costs[n - 1][col];

    int x = 1e9;

    for (int j = 0; j < m; j++)
    {
        if (j != col)
        {
            x = min(x, minCost(costs, n - 1, m, j));
        }
    }

    return dp[n][col] = temp_cost + x;
}

int solve(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    memset(dp, -1, sizeof(dp));

    int res = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        res = min(res, minCost(matrix, n, m, i));
    }

    return res;
}

int minCost(vector<vector<int>> &costs, int n, int col)
{
    if (n <= 0)
        return 0;
    // if(n==1) return min({costs[0][0],costs[0][1],costs[0][2]});

    int temp_cost = costs[n - 1][col];

    int x = 0;

    if (col == 0)
        x = min(minCost(costs, n - 1, 1), minCost(costs, n - 1, 2));
    if (col == 1)
        x = min(minCost(costs, n - 1, 0), minCost(costs, n - 1, 2));
    if (col == 2)
        x = min(minCost(costs, n - 1, 0), minCost(costs, n - 1, 1));

    return temp_cost + x;
}

int MinCostPaint(vector<vector<int>> &costs, int n)
{
    int res = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        res = min(res, minCost(costs, n, i));
    }
}

void minCost(vector<vector<int>> &costs, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
                dp[i][j] = 0;

            else
            {
                int temp_cost = costs[i - 1][j];

                int x = 0;

                if (j == 0)
                    x = min(dp[i - 1][1], dp[i - 1][2]);
                if (j == 1)
                    x = min(dp[i - 1][0], dp[i - 1][2]);
                if (j == 2)
                    x = min(dp[i - 1][0], dp[i - 1][1]);

                dp[i][j] = temp_cost + x;
            }
        }
    }

    int res = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        res = min(res, dp[n][i]);
    }

    cout << "cost = " << res << endl;
}

int minCosts(vector<vector<int>> &costs, int N)
{
    // Corner Case
    if (N == 0)
        return 0;

    // Auxiliary 2D dp array
    vector<vector<int>> dp(N, vector<int>(3, 0));

    // Base Case
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i = 1; i < N; i++)
    {

        // If current house is colored
        // with red the take min cost of
        // previous houses colored with
        // (blue and green)
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];

        // If current house is colored
        // with blue the take min cost of
        // previous houses colored with
        // (red and green)
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];

        // If current house is colored
        // with green the take min cost of
        // previous houses colored with
        // (red and blue)
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
    }

    // Print the min cost of the
    // last painted house
    cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}