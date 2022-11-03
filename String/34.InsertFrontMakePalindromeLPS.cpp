#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string s)
{
    int n = s.length();
    vector<int> LPS(n);

    int len = 0;
    LPS[len] = 0;
    int i = 1;

    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            LPS[i++] = len;
        }
        else
        {
            if (len != 0)
            {
                len = LPS[len - 1];
            }
            else
            {
                LPS[i++] = 0;
            }
        }
    }
    return LPS;
}

int solve(string s)
{
    string rs = s;

    reverse(rs.begin(), rs.end()); // reverse the string
     
    string c = s + "$" + rs; // concat with $ and rs
    
    vector<int> LPS = computeLPSArray(c); // compute LPS of new str
    
    return (s.length() - LPS.back()); // S.len - LPS[n-1]
}