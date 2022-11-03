#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> m;

bool solve(string s)
{
    if (s.size() == 0)
        return 1;

    for (int i = 1; i <= s.size(); i++)
    {
        string temp = (s.substr(0, i));
        if (m[temp] > 0 && solve(s.substr(i, s.size() - i + 1)))
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    for (int i = 0; i < wordDict.size(); i++)
    {
        m[wordDict[i]]++;
    }

    return solve(s);
}

unordered_map<string, int> m;
bool solve(string s)
{
    int n = s.size();

    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 0; i <= n; i++) // denotes end
    {
        for (int j = i; j >= 0; j--) // denotes start
        {
            if (dp[j] && m.find(s.substr(j, i - j)) != m.end())
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}
bool wordBreak(string s, vector<string> &wordDict)
{
    for (int i = 0; i < wordDict.size(); i++)
    {
        m[wordDict[i]]++;
    }

    return solve(s);
}