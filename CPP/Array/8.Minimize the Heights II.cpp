#include <bits/stdc++.h>

using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    priority_queue<int> mxh;
    priority_queue<int, vector<int>, greater<int>> mnh;

    for (int i = 0; i < n; i++)
    {
        mxh.push(arr[i] - k);
        mnh.push(arr[i] + k);
    }

    return mxh.top() - mnh.top();

    // code here
}