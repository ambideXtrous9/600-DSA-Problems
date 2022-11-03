#include <bits/stdc++.h>

using namespace std;

// 287. Find the Duplicate Number

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int x = 1;
    for (int i = 2; i <= n; i++)
    {
        x ^= i;
    }
    for (int i = 0; i < n; i++)
    {
        x ^= nums[i];
    }
    return x;
}

int findDuplicate(vector<int> &nums)
{
    map<int, int> M;

    for (int i = 0; i < nums.size(); i++)
    {
        if (M[nums[i]] == 0)
        {
            M[nums[i]]++;
        }
        else
            return nums[i];
    }
}