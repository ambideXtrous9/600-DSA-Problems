#include <bits/stdc++.h>

using namespace std;

string smallestWindow(string s, string t)
{
    int i = 0;
    int j = 0;
    int n = s.length();

    unordered_map<char, int> mp;
    
    int mn = INT_MAX;
    int tempi = 0;

    for (int i = 0; i < t.length(); i++)
    {
        mp[t[i]]++;
    }
    
    int count = mp.size();

    while (j < n)
    {
        mp[s[j]]--;
        if (mp[s[j]] == 0)
            count--;
        if(count>0) j++;
        else if(count == 0)
        {
            while (count == 0)
            {
                if (mn > j - i + 1)
                {
                    mn = j - i + 1;
                    tempi = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] == 1)
                    count++;

                i++;
            }
            j++;
        }
    }
    if (mn == INT_MAX)
        return "-1";
    else
        return s.substr(tempi, mn);
}