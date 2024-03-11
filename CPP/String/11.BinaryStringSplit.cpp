#include <bits/stdc++.h>
using namespace std;

int maxSubStr(string str)
{
    int res = 0;
    int n = str.length();

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt == 0)
        {
            res++;
        }
    }

    if (cnt == 0)
        return res;
    return -1;
    // Write your code here
}