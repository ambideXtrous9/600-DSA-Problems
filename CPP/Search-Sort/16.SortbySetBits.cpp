#include <bits/stdc++.h>

using namespace std;

int CountSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
void sortBySetBitCount(int arr[], int n)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        int x = CountSetBits(arr[i]);
        ans.push_back({arr[i], x});
    }
    stable_sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i].first;
    }
}

static bool comp(int a, int b)
{
    return __builtin_popcount(a) > __builtin_popcount(b);
}
void sortBySetBitCount(int arr[], int n)
{
    // Your code goes here
    stable_sort(arr, arr + n, comp);
}