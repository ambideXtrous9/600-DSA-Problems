#include <bits/stdc++.h>

using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_set<int> S;
    for (int i = 0; i < n; i++)
    {
        S.insert(a1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (S.find(a2[i]) == S.end())
            return "No";
    }
    return "Yes";
}