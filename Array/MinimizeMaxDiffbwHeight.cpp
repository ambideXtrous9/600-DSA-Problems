#include <bits/stdc++.h>

using namespace std;

int getMinDiff(int arr[], int n, int k) 
    {
        sort(arr,arr+n);
        
        int ans = arr[n-1]-arr[0];
        
        int mina,maxa;
        
        int low = arr[0]+k;
        
        int high = arr[n-1]-k;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=k)
            {
                mina = min(arr[i]-k,low);
                maxa = max(arr[i-1]+k,high);
                ans = min(ans,maxa-mina);
            }
            
        }
        return ans;
    }