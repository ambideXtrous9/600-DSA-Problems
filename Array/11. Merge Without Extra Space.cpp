#include <bits/stdc++.h>

using namespace std;

// //optimal-using greedy approach-O(nlogn + mlogm), AS-O(1)

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);

            i--;
            j++;
        }
        else
            break;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}