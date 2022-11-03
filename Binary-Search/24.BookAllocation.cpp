#include <bits/stdc++.h>

using namespace std;

bool isPossible(int stalls[], int minDist, int k, int n)
{
    int cows = 1; // we already place it at the first available slot i.e stalls[0]  ( GREEDY )
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += stalls[i];
        if (sum > minDist)
        {
            cows++;
            sum = stalls[i];
            if (cows > k)
                return false;
        }
    }
    return true;
}

int findPages(int stalls[], int n, int k)
{

    int low = INT_MIN;
    int high = 0;

    for (int i = 0; i < n; i++)
    {
        high += stalls[i];
        low = max(low, stalls[i]);
    }

    if (k > n)
        return -1;

    int res = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, mid, k, n))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}