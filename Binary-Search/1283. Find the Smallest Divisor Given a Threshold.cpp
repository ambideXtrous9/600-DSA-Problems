#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> &A, int mid, int T)
{
    int ct = 0;

    for (auto x : A)
    {
        ct += (x / mid);

        if (x % mid != 0)
            ct++;

        if (ct > T)
            return false;
    }

    return true;
}

int smallestDivisor(vector<int> &nums, int threshold)
{

    int s = 1;

    int e = 1e6;

    int res = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (func(nums, mid, threshold))
        {
            res = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return res;
}