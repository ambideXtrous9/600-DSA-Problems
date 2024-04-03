#include <bits/stdc++.h>

using namespace std;

bool isPossible(int stalls[], long long minDist, int k, int n)
{
    int cows = 1; // we already place it at the first available slot i.e stalls[0]  ( GREEDY )
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += stalls[i];
        if (sum > minDist)
        {
            cows++;
            sum = stalls[i];

            if (cows > k || stalls[i] > minDist)
                return false;
        }
    }
    return true;
}

long long sum(int stalls[], int n)
{
    long long s = 0;
    for (int i = 0; i < n; i++)
        s += stalls[i];
    return s;
}

long long minTime(int stalls[], int n, int k)
{

    long long low = 0;
    long long high = sum(stalls, n); //

    long long res = -1;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (isPossible(stalls, mid, k, n)) // as we need to minimize the max capacity of a student for less burden
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}