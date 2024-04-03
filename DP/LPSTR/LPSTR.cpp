#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    if (n == 0)
        return "";

    // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
   vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    // Initialize with false

    // Every Single character is palindrome
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    string ans = "";
    ans += s[0];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                // If it is of 2 character OR if its susbtring is palindrome.
                if (j - i == 1 || dp[i + 1][j - 1])
                {
                    // Then it will also a palindrome substring
                    dp[i][j] = true;

                    // Check for Longest Palindrome substring
                    if (ans.size() < j - i + 1)
                        ans = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return ans;
}

int longestPalindrome(string s, int m)
{
    int n = s.size();
    if (n == 0)
        return 0;

    // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    // Initialize with false

    // Every Single character is palindrome
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    int res = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                // If it is of one character OR if its susbtring is palindrome.
                if (j - i == 1 || dp[i + 1][j - 1])
                {
                    // Then it will also a palindrome substring
                    dp[i][j] = true;
                    // Check for Longest Palindrome substring

                    res = max(res, j - i + 1);
                }
            }
        }
    }
    return res;
}

// Manacher's Algorithm

string longestPalindrome(string str)
{
    int n = str.length();
    int res = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        int l = i;
        int r = i;

        while (l >= 0 && r < n && str[l] == str[r])
        {
            if ((r - l + 1) > res)
            {
                res = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }

        l = i;
        r = i + 1;

        while (l >= 0 && r < n && str[l] == str[r])
        {
            if ((r - l + 1) > res)
            {
                res = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }

    return str.substr(start, res);
}