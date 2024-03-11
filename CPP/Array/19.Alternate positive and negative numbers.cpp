#include <bits/stdc++.h>

using namespace std;

void rearrange(int arr[], int n)
{
    vector<int> posarr;
    vector<int> negarr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negarr.push_back(arr[i]);
        }
        else
        {
            posarr.push_back(arr[i]);
        }
    }
    int p = 0, ne = 0, i = 0;
    while (i < n)
    {
        if (p != posarr.size())
        {
            arr[i++] = posarr[p++];
        }
        if (ne != negarr.size())
        {
            arr[i++] = negarr[ne++];
        }
    }
}