#include <bits/stdc++.h>

using namespace std;

int minFlips(string s)
{
    int count = 0, count1 = 0, n = s.size();
    
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && s[i] == '1' || i % 2 != 0 && s[i] == '0')
            count++;
        else if (i % 2 == 0 && s[i] == '0' || i % 2 != 0 && s[i] == '1')
            count1++;
    }
    return min(count, count1);
}