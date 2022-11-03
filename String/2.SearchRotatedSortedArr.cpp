#include <bits/stdc++.h>

using namespace std;

int findminid(vector<int> &nums, int n)
{
    int e = n - 1;
    int s = 0;
    int res = -1;

    if (n == 1)
        return 0;

    while (s <= e)
    {
        if (nums[s] < nums[e])
            return s;
        
        int mid = s + (e - s) / 2;

        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if (nums[mid] < nums[prev] && nums[mid] < nums[next])
        {
            return mid;
        }
        else if (nums[0] > nums[mid]) // always search in unsorted path
            e = mid - 1;
        else
            s = mid + 1; //  always search in unsorted path
    }
    return res;
}
int BS(vector<int> &nums, int target, int s, int e)
{
    int res = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return res;
}

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
        return -1;

    if (n == 1 && nums[0] == target)
        return 0;
    if (n == 1 && nums[0] != target)
        return -1;

    int minid = findminid(nums, n);

    if (nums[minid] == target)
        return minid;
    int d1 = BS(nums, target, minid, n - 1);
    int d2 = BS(nums, target, 0, minid - 1);

    if (d1 == -1 && d2 == -1)
        return -1;
    else if (d1 != -1 && d2 == -1)
        return d1;
    else if (d1 == -1 && d2 != -1)
        return d2;
    return -1;
}