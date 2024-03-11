#include <bits/stdc++.h>

using namespace std;

/*
1. for counting we need to maintain an additional array for count 
2. when we found LIS[i] == LIS[j] + 1 then -> cnt[i] += cnt[j] 
*/

int LISS(vector<int> arr,int n)
{
    vector<int> LIS(n,1);
    vector<int> CNT(n,1);

    int cntlis = 0;

    if(n==0) return 0;

    int ans = 1;

    for(int i = 0;i<n;i++)
    {
        LIS[i] = 1;

        for(int j = 0;j<i;j++)
        {
            if(arr[i]>arr[j] )
            {
                if(LIS[i] < LIS[j] + 1)
                {
                    LIS[i] = LIS[j]+1;
                    CNT[i] = CNT[j];
                }
                else if(LIS[i] == LIS[j] + 1)
                {
                    CNT[i] += CNT[j];
                }
            }
        }
        ans = max(ans,LIS[i]);
    }

    for(int i = 0;i<n;i++) if(LIS[i]==ans) cntlis += CNT[i];

    return cntlis;
}
