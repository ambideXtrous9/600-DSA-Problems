#include <bits/stdc++.h>

using namespace std;

bool solve(string S)
{
    int count = 0;
    int n = S.size();

    unordered_map<char, int> mp;
    
    for (int i = 0; i < n; i++)
        mp[S[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (mp[S[i]] % 2 == 1)
        {
            count++;
            mp.erase(S[i]);
        }
    }
    if (count > 1)
        return 0;
    return 1;
}