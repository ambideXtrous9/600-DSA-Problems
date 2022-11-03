#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v;

int solve(vector<int> P1,vector<int> P2,vector<int> P3)
{
    int n = P1.size();
    int m = P2.size();
    int l = P3.size();

    priority_queue<v,vector<v>,greater<v>> M;

    if(n!=0) M.push({P1[0],0,0});
    if(m!=0) M.push({P2[0],0,1});
    if(l!=0) M.push({P3[0],0,2});

    int ans = 0;

    while(!M.empty())
    {

        auto x = M.top();
        M.pop();

        ans += x[0];
        
        int arr = x[2];
        int idx = x[1];
        
        if(arr == 0 && idx+1<n) M.push({P1[idx+1],idx+1,arr});
        else if(arr == 1 && idx+1<m) M.push({P2[idx+1],idx+1,arr});
        else if(arr == 2 && idx+1<l) M.push({P3[idx+1],idx+1,arr});
    }

    return ans;
    
}