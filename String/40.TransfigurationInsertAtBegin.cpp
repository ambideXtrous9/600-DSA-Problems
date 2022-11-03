#include <bits/stdc++.h>

using namespace std;

int transfigure(string A, string B)
{
    int arr[256];
    memset(arr, 0, sizeof(arr));

    int n = A.length();
    int m = B.length();

    if (n != m)
        return -1;

    for (int i = 0; i < n; i++)
    {
        arr[A[i]]++;
        arr[B[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (arr[i] != 0)
            return -1;
    }

    int i = n - 1;
    int j = m - 1;

    int res = 0;

    while (i >= 0)
    {
        if (A[i] == B[j])
        {
            j--;
        }
        else
        {
            res++;
        }

        i--;
    }

    return res;
}