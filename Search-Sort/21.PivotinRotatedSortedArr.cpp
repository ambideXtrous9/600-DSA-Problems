#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums)
{

    int n = nums.size();

    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int m = (h - l) / 2 + l;

        int prev = (m - 1 + n) % n;
        int next = (m + 1) % n;

        if (nums[m] < nums[prev] && nums[m] < nums[next])
            return nums[m];

        else if (nums[m] > nums[h])
            l = m + 1;

        else
            h = m - 1;
    }

    return nums[l];
}

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (n == 1)
            return nums[0];
        if (nums[s] < nums[e])
            return nums[s];
        int mid = s + (e - s) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if (nums[prev] > nums[mid] && nums[next] > nums[mid])
            return nums[mid];

        else if (nums[0] > nums[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }

    return -1;
}