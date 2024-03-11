#include <bits/stdc++.h>

using namespace std;

int CountPS(string s)
{
    int n = s.length();
    if (n == 0)
        return 0;

    // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    // Initialize with false

    // Every Single character is palindrome

    int res = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = true; // 
                res++;   // single char as palindrome substr
            }

            else if (s[i] == s[j])
            {
                // If it is of 2 character OR if its susbtring is palindrome.
                if (j - i == 1 || dp[i + 1][j - 1])
                {
                    // Then it will also a palindrome substring
                    dp[i][j] = true;
                    // Check for Longest Palindrome substring

                    if (j - i >= 1)  // palindrome substr len >= 1
                        res++;
                }
            }
        }
    }
    return res;
}