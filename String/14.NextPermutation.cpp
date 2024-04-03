#include <bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(int N, vector<int> arr)
{
    vector<int> V;
    int n = arr.size();
    int k = 0;
    int l = 0;
    for (k = n - 2; k >= 0; k--)
    {
        if (arr[k] < arr[k + 1])
            break;
        ;
    }
    if (k < 0)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for (l = n - 1; l > k; l--)
    {
        if (arr[l] > arr[k])
            break;
    }
    swap(arr[l], arr[k]);
    reverse(arr.begin() + k + 1, arr.end());
    return arr;
}