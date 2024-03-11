#include <bits/stdc++.h>

using namespace std;

string countAndSay(int n)
{
    if (n == 0)
        return "";
    string res = "1";
    
    while (--n)
    {
        string cur = "";
        for (int i = 0; i < res.size(); i++)
        {
            int count = 1;
            while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
            {
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}

string countAndSay(int n, string s = "1")
{
    if (n == 1)
        return s;
    int i = 0, j, len = s.size();
    string ans = "";
    while (i < len)
    {
        j = i;
        while (i < len && s[i] == s[j])
            i++; // substring is [j,i-1] & "i-j" is the count
        ans += to_string(i - j) + s[j];
    }
    return countAndSay(n - 1, ans);
}