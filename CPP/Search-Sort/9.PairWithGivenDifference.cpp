#include <bits/stdc++.h>

using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int i = 0, j = 1;

    while (i < size && j < size)
    {
        if (arr[j] - arr[i] == n && i != j)
            return true;
        else if (arr[j] - arr[i] < n)
            j++;
        else
            i++;
    }
    return false;
    // code
}

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    
    for (int i = 0; i < size; i++)
    {
        int find = arr[i] + n;
    
        int start = i + 1;
        int end = size - 1;
    
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == find)
                return true;
            else if (arr[mid] > find)
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return false;
}