#include <bits/stdc++.h>

using namespace std;

/*
number of subarrays with k different integers = (number of subarrays with number of different integers
less than equal to k ) - (number of subarrays with number of different integers less than equal to k-1 )
*/

int solve(vector<int> &nums, int k)
{
    unordered_map<int, int> M;

    int n = nums.size();

    int cnt1 = 0;

    int i = 0;
    int j = 0;

    while (j < n)
    {
        M[nums[j]]++;

        if (M.size() <= k)
        {
            // (i-j+1) = number of subarrays ending at j-th position
            // which contains number of different integers less than or equal to k
            cnt1 += (j - i + 1);
            j++;
        }

        else
        {
            while (M.size() > k)
            {
                M[nums[i]]--;

                if (M[nums[i]] == 0)
                    M.erase(nums[i]);

                i++;
            }

            cnt1 += (j - i + 1);

            j++;
        }
    }

    cout << cnt1 << " ";

    return cnt1;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}