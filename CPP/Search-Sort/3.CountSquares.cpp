#include <bits/stdc++.h>

using namespace std;

int countSquares(int x)
{
    long low = 0; 
    int high = x;

    long ans = -1;
    
    while (low <= high)
    {
        long mid = (low + high) / 2;

        long midsq = mid * mid;

        if (midsq >= x)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }

    return (int)ans;
}

int countSquares(int N)
{
    int count = 0;
    for (int i = 1; (i * i) < N; i++)
    {
        count++;
    }
    return count;
}

int countSquares(int N)
{
    // code here
    return sqrt(N - 1);
}