#include <bits/stdc++.h>

using namespace std;

int lps(string S)
{
    int n = S.length();
    vector<int> LPS(n, 0);
    int len = 0;
    LPS[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (S[i] == S[len]) // match
        {
            LPS[i] = ++len;
            i++;
        }
        else // mismatch
        {
            if (len != 0) //
            {
                len = LPS[len - 1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
    return LPS[n - 1];
}