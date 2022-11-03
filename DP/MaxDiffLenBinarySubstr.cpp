#include <bits/stdc++.h>

using namespace std;

int maxSubstring(string s)
{
    int n = s.length();
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            sum += 1;
        else if (s[i] == '1')
            sum -= 1;

        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans != 0 ? ans : -1;
}