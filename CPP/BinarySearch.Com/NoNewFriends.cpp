#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<vector<int>>& f) 
{
    unordered_set<int> S;
    
    for(int i=0;i<f.size();i++)
    {
        S.insert(f[i][0]);
        S.insert(f[i][1]);
    }

    return S.size()==n;   
}