#include <bits/stdc++.h>

using namespace std;

bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
        // Fix the second element as A[j]
        for (int j = i + 1; j < arr_size - 1; j++)
        {
            // Now look for the third number
            for (int k = j + 1; k < arr_size; k++)
            {
                if (A[i] + A[j] + A[k] == sum)
                {
                    cout << "Triplet is " << A[i] << ", " << A[j] << ", " << A[k];
                    return true;
                }
            }
        }
    }
    // If we reach here, then no triplet was found
    return false;
}

bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
       
        int curr_sum = sum - A[i];
       
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i], A[j], curr_sum - A[j]);
                return true;
            }
            
            s.insert(A[j]);
        }
    }

    // If we reach here, then no triplet was found
    return false;
}

bool triplet(int A[], int n, int X, int K)
{
    if (K == 0 && X == 0)
        return 1;
    if (n == 0)
        return 0;

    if (X >= A[n - 1])
        return (triplet(A, n - 1, X - A[n - 1], K - 1) || triplet(A, n - 1, X, K));
    else
        return triplet(A, n - 1, X, K);
}

bool find3Numbers(int A[], int n, int X)
{
    int K = 3;
    return triplet(A, n, X, K);
}

int triplet(int A[], int n, int X, int K, vector<vector<vector<int>>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            for (int k = 1; k <= K; k++)
            {
                if (j >= A[i - 1])
                    dp[i][j][k] = dp[i - 1][j - A[i - 1]][k - 1] || dp[i - 1][j][k];
                else
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }

    return dp[n][X][K];
}

bool find3Numbers(int A[], int n, int X)
{
    int K = 3;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(X + 1, vector<int>(K + 1, 0)));
    return triplet(A, n, X, K, dp);
}

// triplet sum to 0

vector<vector<int>> threeSum(vector<int> &num)
{
    vector<vector<int>> res;
    sort(num.begin(), num.end());

    // moves for a
    for (int i = 0; i < (int)(num.size()) - 2; i++)
    {

        if (i == 0 || (i > 0 && num[i] != num[i - 1]))
        {

            int lo = i + 1, hi = (int)(num.size()) - 1, sum = 0 - num[i];

            while (lo < hi)
            {
                if (num[lo] + num[hi] == sum)
                {

                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[lo]);
                    temp.push_back(num[hi]);
                    res.push_back(temp);

                    while (lo < hi && num[lo] == num[lo + 1])
                        lo++;
                    while (lo < hi && num[hi] == num[hi - 1])
                        hi--;

                    lo++;
                    hi--;
                }
                else if (num[lo] + num[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return res;
}

bool find3Numbers(int A[], int n, int sum)
{
    int l, r;
    int arr_size = n;
    /* Sort the elements */
    sort(A, A + arr_size);
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++)
    {

        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements
        r = arr_size - 1; // index of the last element
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == sum)
            {
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}