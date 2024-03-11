#include <bits/stdc++.h>

using namespace std;

vector<int> find(int arr[], int n, int x)
{

    int idx1 = lower_bound(arr, arr + n, x) - arr;
    int idx2 = upper_bound(arr, arr + n, x) - arr - 1;

    if (arr[idx1] != x && arr[idx2] != x)
        return {-1, -1};

    return {idx1, idx2};
}

int bsl(int arr[], int n, int x)
{
    int l = 0;

    int r = n - 1;
    int ind = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            ind = mid;
            r--;
        }
        else if (arr[mid] > x)
        {
            r--;
        }
        else
            l++;
    }
    return ind;
}

int bsr(int arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    int ind = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            ind = mid;
            l++;
        }
        else if (arr[mid] > x)
        {
            r--;
        }
        else
            l++;
    }
    return ind;
}

vector<int> find(int arr[], int n, int x)
{
    vector<int> V;
    int l = bsl(arr, n, x);
    int r = bsr(arr, n, x);
    V.push_back(l);
    V.push_back(r);
    return V;
}