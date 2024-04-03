#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    if (n <= 1)
        return 0;

    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        int next = (mid + 1);
        int prev = (mid - 1);

        if ((mid == 0 || nums[mid] > nums[prev]) && (mid == n - 1 || nums[mid] > nums[next]))
            return mid;

        else if (prev >= 0 && nums[prev] > nums[mid])
        {
            h = mid - 1;
        }
        else if (next < n && nums[next] > nums[mid])
        {
            l = mid + 1;
        }
    }

    return 0;
}