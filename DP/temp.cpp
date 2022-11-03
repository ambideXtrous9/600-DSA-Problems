#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LAS(vector<int> const &A, int n, vector<vector<vector<int>>> &dp)
{
    int res = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            for (int flag = 0; flag <= 1; flag++)
            {
                int result = 0 + dp[ind + 1][prev + 1][flag];

                if (prev == -1 || (flag && A[prev] < A[ind]))
                {
                    result = max(result, 1 + dp[ind + 1][ind + 1][!flag]);
                }
                else if (prev == -1 || (!flag && A[prev] > A[ind]))
                {
                    result = max(result, 1 + dp[ind + 1][ind + 1][!flag]);
                }
                dp[ind][prev + 1][flag] = result;
                res = max(res, dp[ind][prev + 1][flag]);
            }
        }
    }

    return res;
}

int AlternatingaMaxLength(vector<int> &A)
{
    int n = A.size();

    // base case
    if (n == 0)
    {
        return 0;
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, 0)));

    return LAS(A, n, dp);
}

int main()
{
    vector<int> A = {13, 4, 17};

    // Find the longest alternating subsequence
    cout << "The length of the longest alternating subsequence is =  " << AlternatingaMaxLength(A) << endl;

    return 0;
}