#include <bits/stdc++.h>

using namespace std;

int doUnion(int a[], int n, int b[], int m)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        mp[b[i]]++;
    }
    return mp.size();
    // code here
}