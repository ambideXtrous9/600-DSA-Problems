#include <bits/stdc++.h>

using namespace std;

int LAS(vector<int> const &A, int ind, int prev, int n, bool flag)
{
    if (ind == n) return 0;
    
    int result = 0;
    
    result = max(result, LAS(A, ind + 1, prev, n, flag)); // not Taken
    
    // Taken
    if (prev == -1 || (flag && A[prev] < A[ind]))
    {
        result = max(result, 1 + LAS(A, ind + 1, ind, n, !flag));
    }

    else if (prev == -1 || (!flag && A[prev] > A[ind]))
    {
        result = max(result, 1 + LAS(A, ind + 1, ind, n, !flag));
    }

    return result;
}

int AlternatingaMaxLength(vector<int> &A)
{
    int n = A.size();
    // base case
    if (n == 0) return 0;
    
    return max(LAS(A, 0, -1, n, true), LAS(A, 0, -1, n, false));
}

int LAS(vector<int> const &A, int ind, int prev, int n, bool flag,vector<vector<vector<int>>> &dp)
{

    if (ind == n)
        return 0;

    int result = 0;

    if(dp[ind][prev+1][flag]!=-1) return dp[ind][prev+1][flag];

    result = max(result, LAS(A, ind + 1, prev, n, flag,dp)); // not Taken

    // Taken
    if (prev == -1 || (flag && A[prev] < A[ind]))
    {
        result = max(result, 1 + LAS(A, ind + 1, ind, n, !flag,dp));
    }

    else if (prev == -1 || (!flag && A[prev] > A[ind]))
    {
        result = max(result, 1 + LAS(A, ind + 1, ind, n, !flag,dp));
    }

    return dp[ind][prev+1][flag] = result;
}

int AlternatingaMaxLength(vector<int> &A)
{
    int n = A.size();

    // base case
    if (n == 0)
    {
        return 0;
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1,vector<int>(2,-1)));

    return max(LAS(A, 0, -1, n, true,dp), LAS(A, 0, -1, n, false,dp));
}

int LAS(vector<int> const &A,int n,vector<vector<vector<int>>> &dp)
{
    int res = 0;

    for (int ind = n-1; ind >= 0; ind--)
    {
        for (int prev = ind-1; prev >= -1; prev--)
        {
            for(int flag=0;flag<=1;flag++)
            {
                int result = 0 + dp[ind+1][prev+1][flag];

                if (prev == -1 || (flag && A[prev] < A[ind]))
                {
                    result = max(result, 1 + dp[ind+1][ind+1][!flag]);
                }
                else if (prev == -1 || (!flag && A[prev] > A[ind]))
                {
                    result = max(result, 1 + dp[ind+1][ind+1][!flag]);
                }
                
                dp[ind][prev+1][flag] = result;
                res = max(res,dp[ind][prev+1][flag]);
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

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1,vector<int>(3,0)));

    return LAS(A, n,dp);
}



int AlternatingaMaxLength(vector<int> &nums)
{
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
            up = down + 1;

        else if (nums[i] < nums[i - 1])
            down = up + 1;
    }
    return max(down, up);
}