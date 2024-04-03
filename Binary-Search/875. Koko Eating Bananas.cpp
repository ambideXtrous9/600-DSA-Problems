#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> &A, int mid, int h)
{
    int n = A.size();

    long long int hr = 0;

    for (auto x : A)
    {
        long long int div = x / mid;

        hr += div;

        if (x % mid != 0)
            hr++;
    }

    return hr <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{

    int s = 1;
    int e = INT_MIN;

    for (auto x : piles)
        e = max(e, x);

    int res = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (func(piles, mid, h))
        {
            res = mid;

            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return s;
}