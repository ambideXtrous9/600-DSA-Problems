#include <bits/stdc++.h>

using namespace std;

int numberOfSubstrings(string s)
{
    int n = s.length();

    unordered_map<char, int> M;

    int i = 0;
    int j = 0;

    int ans = 0;

    while (j < n)
    {
        M[s[j]]++;

        if (M.size() < 3)
        {
            j++;
        }
        else
        {
            while (M.size() == 3)
            {
                // (n-j) because the at the index j at which the size of map becomes 3 the next j index will also satisfy the given condition
                ans += (n - j);

                M[s[i]]--;

                if (M[s[i]] == 0)
                    M.erase(s[i]);

                i++;
            }

            j++;
        }
    }

    return ans;
}