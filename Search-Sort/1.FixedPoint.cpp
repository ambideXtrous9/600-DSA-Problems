#include <bits/stdc++.h>

using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> V;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
            V.push_back(arr[i]);
    }

    return V;
}