#include <bits/stdc++.h>

using namespace std;

/*
If you write mean of some subarray let say (a + b + c + d) / 4 = k,
where k is the mean, this can be written as (a + b + c + d) = 4k ,
it can be further written as
(a + b + c + d - 4k) = 0 => (a - k) + (b - k) + (c - k) + (d - k) = 0
The problem now transforms to find number of subarrays with sum 0,
instead of take arr[i] you have to take (arr[i] - k).
*/

int subarraySum(vector<int> &nums)
{
    int target = 0;

    unordered_map<int, int> mp;

    int sum = 0, ans = 0;

    for (auto x : nums)
    {
        sum += (x - target);

        if (sum == target)
            ans++;

        int find = sum - target;

        if (mp.find(find) != mp.end())
        {
            ans += mp[find];
        }
        mp[sum]++;
    }
    return ans;
}