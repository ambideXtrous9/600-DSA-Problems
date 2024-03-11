#include <bits/stdc++.h>

using namespace std;



// order maintained
void segregateElements(int arr[], int n)
{
    int arr1[n];
    int arr2[n];
    int j = 0, k = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            arr1[j++] = arr[i];
        else
            arr2[k++] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i < j)
        {
            arr[i] = arr1[i];
        }
        else
        {
            arr[i] = arr2[i - j];
        }
    }
}


// order not maintained

void func(int arr[], int n)
{
    int nidx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            swap(arr[i], arr[nidx]);
            nidx++;
        }
    }
}

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

        if (l <= r)
        {
            swap(arr[l], arr[r]);
            r--;
            l++;
        }
    }
}