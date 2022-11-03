#include <bits/stdc++.h>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> M;

    int i = 0;
    int j = 0;

    while (j < n)
    {
        M[nums[j]]++;

        if (abs(j - i) <= k)
        {
            if (i != j)
            {
                if (M[nums[j]] > 1)
                    return true;
            }

            j++;
        }
        else
        {
            M[nums[i]]--;

            if (M[nums[i]] == 0)
                M.erase(nums[i]);
            i++;

            if (abs(j - i) <= k)
            {
                if (i != j)
                {
                    if (M[nums[j]] > 1)
                        return true;
                }
            }

            j++;
        }
    }

    return false;
}