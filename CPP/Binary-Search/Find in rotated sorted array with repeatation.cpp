#include <bits/stdc++.h>

using namespace std;

/*
Logic Explanation:
Core Observation - As we are are given a sorted and rotated array, it is guranteed that either 1/2 of the array is going to be sorted (If you aren't getting this try taking different combinations of provided example array)
Now our first job is to find that sorted half. To do this we can do a simple comparison of mid (mid = (low+high)/2) element with the starting element (low) of the array.
Comparison (do this with pen and paper in hand)

1. if(nums[mid] >= nums[low]) -> the left half of array is sorted.
   else -> the right half of array is sorted.

   a.   Now if left half of array is sorted:
        check if provided target element lies in the range [low, mid).
        If it does then update high = mid-1 (hence skipping the part present on right of mid).
        else update low = mid+1 (hence skipping the part present on left of mid)
        else as the right array is sorted:
   
   b.   check if provided target element lies in the range (mid, high].
        If it does then update low = mid+1 (hence skipping the part present on left of mid).
        else update high = mid-1 (hence skipping the part present on right of mid)

2. If still not found then return -1 (duh!)
*/

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
    
        if (nums[mid] == target)
            return mid;

        if (nums[low] <= nums[mid])
        {
            // left half is sorted
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            // right half is sorted
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}


// containing duplicate

bool searchRepeat(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return true;

        // with duplicates we can have this contdition, just update left & right
        if ((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
        {
            l++;
            r--;
            continue;
        }

        // first half
        // first half is in order
        else if (nums[l] <= nums[mid])
        {
            // target is in first  half
            if ((nums[l] <= target) && (nums[mid] > target))
                r = mid - 1;
            else
                l = mid + 1;
        }
        // second half
        // second half is order
        // target is in second half
        else
        {
            if ((nums[mid] < target) && (nums[r] >= target))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}