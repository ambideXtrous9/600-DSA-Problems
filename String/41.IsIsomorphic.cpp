#include <bits/stdc++.h>

using namespace std;

// we need 2 unordered_map

bool areIsomorphic(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    if (n != m)
    {
        return 0;
    }
    unordered_map<char, char> m1;
    unordered_map<char, char> m2;
    for (int i = 0; i < n; i++)
    {
        if (!m1[str1[i]] & !m2[str2[i]])
        {
            m1[str1[i]] = str2[i];
            m2[str2[i]] = str1[i];
        }
        else
        {
            if (m1[str1[i]] != str2[i])
            {
                return 0;
            }
        }
    }
    return 1;
}