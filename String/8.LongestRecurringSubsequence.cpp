// Longest Repeating Subsequence DP-LCS with same str
#include <bits/stdc++.h>

using namespace std;

int LCS_SO(int x, int y, string s1, string s2)
{
    vector<int> prev(y + 1, 0);

    for (int i = 1; i <= x; i++)
    {
        vector<int> cur(y + 1, 0);
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1] && i != j)
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }

    return prev[y];
}


int LongestRepeatingSubsequence(string str)
{
    int n = str.length();
    return LCS_SO(n, n, str, str);
    // Code here
}