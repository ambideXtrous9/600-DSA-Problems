#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> m;

void solve(string &s, int idx, int n, string cur, vector<string> &V)
{
    if (idx == n)
    {
        cur.pop_back(); // pop back extra space at last
        V.push_back(cur);
        return;
    }
    string str = "";
    for (int i = idx; i < n; i++)
    {
        str += s[i];

        if (m[str])
        {
            solve(s, i + 1, n, cur + str + " ", V);
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    for (int i = 0; i < wordDict.size(); i++)
    {
        m[wordDict[i]]++;
    }
    int n = s.length();
    vector<string> V;
    string cur = "";
    solve(s, 0, n, cur, V);
    return V;
}