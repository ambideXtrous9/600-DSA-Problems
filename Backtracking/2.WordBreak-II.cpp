#include <bits/stdc++.h>

using namespace std;

void WB(int n, unordered_set<string> &S, vector<string> &V, string str, string nw)
{
    for (int i = 1; i <= n; i++) // explores all possible substrs
    {
        string s = str.substr(0, i);

        if (S.find(s) != S.end())
        {
            if (i == n)
            {
                nw += s;
                V.push_back(nw);
                return;
            }

            WB(n - i, S, V, str.substr(i, n - i), nw + s + " ");
        }
    }
}

vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    vector<string> V;
    int len = s.length();
    unordered_set<string> S(dict.begin(), dict.end());

    WB(len, S, V, s, "");

    return V;
}