#include <bits/stdc++.h>

using namespace std;

int solve(string S)
{
    unordered_map<char, int> M;

    M['I'] = 1;
    M['V'] = 5;
    M['X'] = 10;
    M['L'] = 50;
    M['C'] = 100;
    M['D'] = 500;
    M['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (M[S[i + 1]] > M[S[i]])
        {
            ans += M[S[i + 1]] - M[S[i]];
            i++;
        }
        else
            ans += M[S[i]];
    }

    return ans;
}