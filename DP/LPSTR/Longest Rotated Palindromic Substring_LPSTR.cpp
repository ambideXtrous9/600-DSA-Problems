#include <bits/stdc++.h>

using namespace std;

int longestPalindrome(string s,int m)
{
    int n = s.size();
    if (n == 0)
        return 0;

    // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
    bool dp[n][n];

    // Initialize with false

    memset(dp, false, sizeof(dp));

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
                // If it is of one character OR if its susbtring is palindrome.
                if (j - i == 1 || dp[i + 1][j - 1])
                {
                    // Then it will also a palindrome substring
                    dp[i][j] = true;

                    // Check for Longest Palindrome substring
                    if (ans.size() < j - i + 1 && (j - i + 1) <=m ) // extra cond on LPSTR  
                        ans = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return ans.length();
}

int solve(string s) 
{
    string t = s;
    
    int m = t.length();

    s += s;

    int n = s.length();
    
    int res1 = longestPalindrome(s,m);

    return res1;
    
}

int longestPalindrome(string str,int m)
{
    int n = str.length();
    int res = 0;
    int start = 0;

    if(n==0) return 0;

    for (int i = 0; i < n; i++)
    {
        int l = i;
        int r = i;

        while (l >= 0 && r < n && str[l] == str[r])
        {
            if ((r - l + 1) > res && (r - l + 1)<=m)
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
            if ((r - l + 1) > res && (r - l + 1)<=m)
            {
                res = r - l + 1;
            }
            l--;
            r++;
        }
    }

    return res;
}

int solve(string s) 
{
    
    int m = s.length();

    s += s;
    
    int res1 = longestPalindrome(s,m);

    return res1;
    
}