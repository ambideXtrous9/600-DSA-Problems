#include <bits/stdc++.h>

using namespace std;

static bool comp(string &s1, string &s2)
{
    return s1.length() < s2.length();
}

bool compare(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0;
    int second = 0;

    while (first < s1.length())
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }

    if (s1.length() == first && s2.length() == second)
        return true;

    return false;
}

int longestStrChain(vector<string> &words)
{

    sort(words.begin(), words.end(), comp);

    int n = words.size();

    vector<int> dp(n + 1, 1);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (compare(words[i], words[j]) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }

        res = max(res, dp[i]);
    }

    return res;
}