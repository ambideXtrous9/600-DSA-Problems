#include <bits/stdc++.h>

using namespace std;

int findSubString(string str)
{
    unordered_map<char, int> M;
    for (auto c : str)
        M[c]++;

    int n = str.length();
    int m = M.size();

    M.clear();
    int i = 0;
    int j = 0;

    int res = INT_MAX;

    while (j < n)
    {
        M[str[j]]++;

        if (M.size() < m)
            j++;

        else if (M.size() >= m)
        {

            while (M.size() >= m)
            {
                res = min(res, j - i + 1);
                M[str[i]]--;
                if (M[str[i]] == 0)
                    M.erase(str[i]);
                i++;
            }
            j++;
        }
    }

    return res;
}