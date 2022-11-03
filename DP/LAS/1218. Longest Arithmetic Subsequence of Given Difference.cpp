#include <bits/stdc++.h>

using namespace std;

// 1218. Longest Arithmetic Subsequence of Given Difference

int longestSubsequence(vector<int> &arr, int diff)
{
    unordered_map<int, int> mp;
    int ans = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        // when element found in map with given CD,
        // then increment the count upto that element
        // and store the max
        if (mp.find(arr[i] - diff) != mp.end())
        {
            int curr = mp[arr[i] - diff] + 1; 

            mp[arr[i]] = curr;      //increment the count upto that element

            ans = max(ans, curr);
        }
        else
        {
            mp[arr[i]] = 1;
        }
    }
    return ans;
}