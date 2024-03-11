#include <bits/stdc++.h>

using namespace std;
void segregateElements(int arr[], int n)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        while (arr[l] > 0 && l < r)
            l++;
        while (arr[r] < 0 && l < r)
            r--;

        if (l < r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
}