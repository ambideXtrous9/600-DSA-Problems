#include <bits/stdc++.h>

using namespace std;


int solve(string S)
{
    int n = S.length();
    int ans = 0;
    unordered_set<char> st;

    for(auto c : S)
    {
        if(st.find(c)!=st.end())
        {
            ans++;
            st.clear();
        }

        st.insert(c);
    }

    return ans+1;
}