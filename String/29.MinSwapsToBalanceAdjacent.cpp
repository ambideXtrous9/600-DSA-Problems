#include <bits/stdc++.h>

using namespace std;

int minimumNumberOfSwaps(string s)
{
    if (s.size() % 2 != 0)
        return -1;

    int open = 0;
    int close = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
            open++;

        else
        {
            open--;

            if (open < 0)
            {
                close = close - open;
            }
        }
    }
    return close;
}