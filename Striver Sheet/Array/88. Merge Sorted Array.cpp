#include <bits/stdc++.h>

using namespace std;



/* 
1. start from end  -> i = m-1, j = n-1, l = (m+n)-1
2. if(nums1[i] >= nums2[j]) nums1[l--] = nums1[i--];
3. else nums1[l--] = nums2[j--];
4. now store rest from nums2 ->  while(j>=0) nums1[l--] = nums2[j--];

*/

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int l = nums1.size() - 1;

    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[l--] = nums1[i--];
        }
        else
        {
            nums1[l--] = nums2[j--];
        }
    }

    while (j >= 0)  // store rest from the second arr
    {
        nums1[l--] = nums2[j--];
    }
}