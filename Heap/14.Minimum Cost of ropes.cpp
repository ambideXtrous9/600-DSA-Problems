#include <bits/stdc++.h>

using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> mnp;

    for (long long i = 0; i < n; i++)
    {
        mnp.push(arr[i]);
    }

    long long res = 0;

    while (mnp.size() >= 2)
    {
        long long temp1 = mnp.top();
        mnp.pop();
        long long temp2 = mnp.top();
        mnp.pop();
        res += temp1 + temp2;
        mnp.push(temp1 + temp2);
    }
    return res;

}