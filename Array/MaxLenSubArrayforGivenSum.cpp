#include <bits/stdc++.h>

using namespace std;

int maxLen(vector<int>&A, int k)
    { 
        unordered_map<int,int> M;
        
        int sum = 0;
        int res = 0;
        for(int i = 0;i<A.size();i++)
        {
            sum += A[i];
            
            if(sum==0) res = max(res,i+1);
            
            
            if(M.find(sum-0)!=M.end())
            {
                res = max(res,i-M[sum-0]);
            }
            else
            {
                M[sum] = i;
            }
            
        }
        
        return res;
        // Your code here
    }
