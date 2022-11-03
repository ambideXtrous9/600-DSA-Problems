#include <bits/stdc++.h>

using namespace std;

bool matching(int i,int j,string s,string p,int n,int m,vector<vector<int>> &dp)
{
    if(i>=n && j>=m) return true;
    
    if(j>=m) return false;

    if(dp[i][j]!=-1) return dp[i][j];

    bool match = (i<n) && (s[i]==p[j] || p[j]=='.');

    if(j+1<m && p[j+1]=='*') // when * at RHS
    {
        // skip the * ->  i, j+2  => skipping the jth char as well
        bool skip = matching(i,j+2,s,p,n,m,dp);

        // use the * -> i+1,j (only when char matches)
        bool not_skip =  (match==true) ?  matching(i+1,j,s,p,n,m,dp) : false;

        return dp[i][j] = (skip || not_skip);
    }

    if(match) // when there is no * in RHS of matching chars
        return dp[i][j] = matching(i+1,j+1,s,p,n,m,dp);
    
    else     // otherwise no match return false;
        return dp[i][j] = false;
}


bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    return matching(0,0,s,p,n,m,dp);

}