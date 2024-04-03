#include <bits/stdc++.h>

using namespace std;

string rremove(string s)
{
    string res = "";
    int n = s.length();

    // process the string
    int i = 0;
    while (i < n)
    {
        char c = s[i];
        int freq = 0;
        while (s[i] == c)
            freq++, i++;

        if (freq == 1)
            res += c;
    }

    if (res == s) return res;
    
    return rremove(res); // is processed string not same as input again call recursively
    // code here
}