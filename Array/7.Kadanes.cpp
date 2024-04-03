#include <bits/stdc++.h>

using namespace std;

long long maxSubarraySum(int arr[], int n)
    {
        int gm = INT_MIN;
        int lm = 0;
        
        for(int i=0;i<n;i++)
        {
            lm+=arr[i];
            gm = max(gm,lm);
            if(lm<0) lm = 0;
        }
        return gm;
        
    }