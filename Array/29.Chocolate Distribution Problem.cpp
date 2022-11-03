#include <bits/stdc++.h>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());  // sort the array

    long long k = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++)
    {
        long long d = a[i + m - 1] - a[i];
        k = min(k, d);
    }
    return k;
}