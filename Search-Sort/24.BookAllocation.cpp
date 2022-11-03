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

int sum(int stalls[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += stalls[i];
    return s;
}

int findPages(int stalls[], int n, int k)
{
    //sort(stalls, stalls + n);

    int low = stalls[n - 1];
    int high = sum(stalls, n); //

    int res = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

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