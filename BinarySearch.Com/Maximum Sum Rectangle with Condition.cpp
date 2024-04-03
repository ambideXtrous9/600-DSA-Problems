#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> &sum, int k)
{
    int row = sum.size();
    int curSum = 0; 
    int curMax = INT_MIN;

    // Stores the values (cum_sum - K)
    set<int> sumSet;

    // Insert 0 into the set sumSet
    sumSet.insert(0);

    // Traverse over the rows
    for (int r = 0; r < row; ++r)
    {

        // Get cumulative sum from [0 to i]
        curSum += sum[r];

        // Search for lowerbound of
        // (cSum - K) in the hashmap
        auto it = sumSet.lower_bound(curSum - k);

        // If upper_bound of (cSum - K)
        // exists, then update max sum
        if (it != sumSet.end())
        {
            curMax = max(curMax,curSum - *it);
        }

        // Insert cumulative value
        // in the hashmap
        sumSet.insert(curSum);
    }

    // Return the maximum sum
    // which is less than K
    return curMax;
}

int solve(vector<vector<int>> &matrix, int k)
{

    int R = matrix.size();
    int C = matrix[0].size();

    int mx = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        vector<int> V(C, 0);
        for (int i1 = i; i1 < R; i1++)
        {
            for (int j = 0; j < C; j++)
            {
                V[j] += matrix[i1][j];
            }
            mx = max(mx, maxSubarraySum(V, k));
        }
    }
    return mx;
}