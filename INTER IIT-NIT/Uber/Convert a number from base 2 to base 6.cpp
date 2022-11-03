#include <bits/stdc++.h>
using namespace std;

// Program to convert the base of
// given binary number to base 6
void convertBase(string N)
{
    // 128 bit integer to store
    // the decimal conversion
    __int128 decimal = 0;

    // Loop to iterate N
    for (int i = 0; i < N.length(); i++)
    {
        // Binary to decimal
        decimal = decimal * 2 + (N[i] - '0');
    }

    // Stores the base 6 int
    vector<int> ans;

    // Decimal to base 6
    while (decimal > 0)
    {
        ans.push_back(decimal % 6);
        decimal = decimal / 6;
    }

    // Print Answer
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
}