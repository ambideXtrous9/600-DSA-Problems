#include <bits/stdc++.h>

using namespace std;

long long trappingWater(int arr[], int n)
{
    int maxl[n];
    int maxr[n];
    
    maxl[0] = arr[0];
   
    for (int i = 1; i < n; i++)
    {
        maxl[i] = max(maxl[i - 1], arr[i]);
    }

    maxr[n - 1] = arr[n - 1];
   
    for (int i = n - 2; i >= 0; i--)
    {
        maxr[i] = max(maxr[i + 1], arr[i]);
    }
    
    long long w[n];
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        w[i] = min(maxl[i], maxr[i]) - arr[i];
        sum += w[i];
    }
    return sum;
}