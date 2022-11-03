#include <bits/stdc++.h>

using namespace std;

int nextGreaterElement(int n)
{
    vector<int> res;
    int temp = n;

    while (n)
    {
        res.push_back(n % 10);
        n /= 10;
    }

    reverse(res.begin(), res.end());

    next_permutation(res.begin(), res.end());

    unsigned long long int ans = 0;

    for (auto c : res)
        ans = ans * 10 + c;

    return (ans <= temp || ans > INT_MAX) ? -1 : ans;
}