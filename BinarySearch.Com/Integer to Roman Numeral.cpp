#include <bits/stdc++.h>

using namespace std;

string solve(int num)
{
    int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string rom[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string s = "";
    int i = 0;

    while (num)
    {
        if (num >= val[i])
        {
            s += rom[i];
            num -= val[i];
            continue;
        }

        i++;
    }
    return s;
}