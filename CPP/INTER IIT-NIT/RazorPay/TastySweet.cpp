#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &W,vector<int> &T,int n,int k)
{
    multiset<pair<long long,int>> M;
    
    vector<long long> dp(n);
    
    long long ans = 0;
    int r = n-1;
    
    for(int i = n-1;i>=0;i--)
    {
        dp[i] = T[i];
        
        if(M.size() > k)
        {
            M.erase({-W[r],r});
            r--;
        }
        
        int idx = (*(M.begin())).second;
        
        if(M.begin()!=M.end()) dp[i] += dp[idx];
        
        M.insert({-W[i],i});
        
        ans = max(ans,dp[i]);
        
    }
    
    return ans;
}

int main()
{
    
    int n = 5;
    vector<int> W = {1,5,3,4,9};
    vector<int> T = {1,2,5,3,1};
    int k = 2;
    
    int x = solve(W,T,n,k);
    
    cout<<x<<endl;
    
    return 0;

}