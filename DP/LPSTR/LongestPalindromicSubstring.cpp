#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int l, int r)
{
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

// TC = O(n^3)

int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();

    // All substrings of length 1
    // are palindromes
    int maxLength = 1, start = 0;
    int end = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            if (isPalindrome(str, i, j) && ((j - i + 1) > maxLength))
            {
                start = i;
                end = j;
                maxLength = j - i + 1;
            }
        }
    }

    string s = s.substr(start, maxLength);

    return maxLength;
}

// Manacher's Algorithm

int longestPalSubstr(string str)
{
    int n = str.length();
    int res = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        int l = i;
        int r = i;
        while (l >= 0 && r < n && str[l] == str[r]) // odd len palindrome
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
        while (l >= 0 && r < n && str[l] == str[r]) // even len palindrome
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

    string s = str.substr(start, res);
    cout << "Longest palindrome substring is: " << s << endl;

    return res;
}