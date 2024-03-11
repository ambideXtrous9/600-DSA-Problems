#include <bits/stdc++.h>

using namespace std;

/*
Algo:

choose contiguous windoe of size m and calculate max sum using 
Sliding window. 

*/

int MinMemory(vector<int> &nums,int m)
{
    int n = nums.size();
    int j = 0;
    int i = 0;
    int sum = 0;
    int temp = 0;

    for(auto x : nums) sum += x;

    int prefsum = 0;

    while(j<n)
    {
        prefsum += nums[j];

        if(j-i+1<m) j++;

        else if(j-i+1 == m)
        {
            temp = max(temp,prefsum);
            j++;
        }
        else
        {
            while(j-i+1>m)
            {
                prefsum -= nums[i];
                i++;
            }
            if(j-i+1 == m)
            {
                temp = max(temp,prefsum);
                j++;
            }
            j++;
        }
    }

    return (sum-temp);
}