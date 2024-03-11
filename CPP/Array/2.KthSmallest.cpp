#include <bits/stdc++.h>

using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    int small = 0;
    priority_queue<int> MH;
    for (int i = 0; i <= r; i++)
    {
        MH.push(arr[i]);
        if (MH.size() > k)
        {
            MH.pop();
        }
    }

    small = MH.top();

    return small;
}