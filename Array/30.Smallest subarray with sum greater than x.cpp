#include <bits/stdc++.h>

using namespace std;

int smallestSubWithSum(int arr[], int n, int x)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int mini = INT_MAX;
    
    while (j < n)
    {
        sum = sum + arr[j];

        if (sum <= x)
            j++;

        else
        {
            while (sum > x)
            {
                mini = min(mini, j - i + 1);
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
    }
    return mini;
}