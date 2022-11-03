#include <bits/stdc++.h>

using namespace std;

bool recur(vector<int> &stones, map<int, int> &mp, int i, int k, vector<vector<int>> &dp)
{
    if (i == stones.size() - 1)
        return dp[i][k] = 1;

    if (dp[i][k] != -1)
        return dp[i][k];

    for (int t = k - 1; t <= k + 1; t++)
    {
        if (t > 0 && mp.find(stones[i] + t) != mp.end())
        {
            int ind = mp[stones[i] + t];
            if (recur(stones, mp, ind, t, dp))
                return dp[i][k] = 1;
        }
    }
    return dp[i][k] = 0;
}
bool canCross(vector<int> &stones)
{
    int n = stones.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[stones[i]] = i;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return recur(stones, mp, 0, 0, dp);
}

// tabulation equivalent
bool canCross(vector<int> &stones)
{
    unordered_map<int, unordered_set<int>> hashMap; // Initializing required hashmap.
    
    hashMap[stones[0] + 1] = {1};                   // Viable Jump Sizes to reach 2nd stone.
    
    for (int i = 1; i < stones.size(); ++i)
    {                             // Traversing all positions
        int position = stones[i]; // Current Position
        for (auto it : hashMap[position])
        {                                      // Traversing all viable jump sizes that can be used from current position.
            hashMap[position + it].insert(it); // Populating the sets of positions that can be reached from current position with a viable jump size.
            hashMap[position + it + 1].insert(it + 1);
            hashMap[position + it - 1].insert(it - 1);
        }
    }
    return hashMap[stones.back()].size() != 0; // Checking the set size of last stone.
}

