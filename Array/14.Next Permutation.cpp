#include <bits/stdc++.h>

using namespace std;

/*
Algorithm:

step 1:
Linearly traverse given array from the end and
find a number that is smaller than its adjacent ->  nums[i] < nums[i+1].
Store the index of smaller number in breakPoint variable.
If there is no such element, reverse entire array and return.

step 2: Linearly traverse from the end and this time find a number larger than nums[breakPoint]. Let's call it nums[i].

step 3: Swap nums[i] and nums[breakPoint].

step 4: Reverse the array from index breakPoint + 1 to nums.size().

Example:

Consider nums[] = [1, 3, 5, 4, 2].

Traverse from back and find a breakpoint. Here, index breakPoint = 1 and nums[breakPoint] = 3
Traverse from back and find a number larger than this. Here this number is: nums[i] = 4
Swap nums[breakPoint] and nums[i]. Value after swapping: nums[] = [1, 4, 5, 3, 2].
Reverse array from breakPoint + 1 to nums.size() i.e. these elements: [1, 4, 5, 3, 2]
Final answer = [1, 4, 2, 3, 5].


*/

void nextPermutation(vector<int> &nums)
{

    int n = nums.size();
    int k = 0;
    int l = 0;

    // find the BP -> a[k] < a[k+1]

    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
            break;
    }

    // when no such element found   -> reversely sorted

    if (k < 0)
        reverse(nums.begin(), nums.end());

    else
    {
        // find a num greater than a[k] from the end

        for (l = n - 1; l >= 0; l--)
        {
            if (nums[l] > nums[k])
                break;
        }

        // now swap 2 nums

        swap(nums[l], nums[k]);

        // then reverse rest after k

        reverse(nums.begin() + k + 1, nums.end());
    }
}

void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int l = 0;
    int k = 0;

    for (k = n - 2; k >= 0; k--)
    {
        if (arr[k] < arr[k + 1])
            break;
    }

    if (k < 0)
        reverse(arr.begin(), arr.end());

    else
    {
        for (l = n - 1; l >= 0; l--)
        {
            if (arr[l] > arr[k])
                break;
        }
        swap(arr[l], arr[k]);
        reverse(arr.begin() + k + 1, arr.end());
    }
}

void nextPermutation(vector<int> &arr)
{
    next_permutation(arr.begin(), arr.end());
}