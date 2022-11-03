#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> &W, int mid, int d)
{
    int day = 1;
    long long int sum = 0;

    for (auto x : W)
    {
        sum += x;

        if (sum > mid)
        {
            day++;
            sum = x;

            if (day > d)
                return false;
        }
    }

    return true;
}

int shipWithinDays(vector<int> &W, int days)
{

    int s = 0;
    int e = 0;

    for (auto x : W)
    {
        s = max(s, x);
        e += x;
    }

    int res = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (func(W, mid, days))
        {
            res = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return res;
}