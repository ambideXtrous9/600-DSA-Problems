#include <bits/stdc++.h>

using namespace std;

int solve(int k, vector<int> &nums)
{

    // sliding window

    unordered_map<int, int> M;

    int n = nums.size();

    int ans = 0;

    int i = 0;
    int j = 0;

    while (j < n)
    {
        M[nums[j]]++;

        if (M.size() <= k)
        {
            ans = max(ans, j - i + 1);
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

            ans = max(ans, j - i + 1);
            j++;
        }
    }

    return ans;
}