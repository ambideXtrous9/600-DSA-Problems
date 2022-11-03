#include <bits/stdc++.h>

using namespace std;

int romanToDecimal(string &S)
{
    int ans = 0;
    unordered_map<char, int> num;
    num['I'] = 1;
    num['V'] = 5;
    num['X'] = 10;
    num['L'] = 50;
    num['C'] = 100;
    num['D'] = 500;
    num['M'] = 1000;

    int ans = 0;
    for(int i = 0;i<S.length();i++)
    {
        if(num[S[i+1]]>num[S[i]])
        {
            ans += num[S[i+1]]-num[S[i]];
            i++;
        }
        else
            ans += num[S[i]];
    }

    return ans;

}