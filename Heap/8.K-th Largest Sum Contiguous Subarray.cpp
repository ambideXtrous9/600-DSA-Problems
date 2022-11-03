#include <bits/stdc++.h>

using namespace std;

int kthLargest(vector<int> &arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> mnh;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;

        for (int j = i; j < N; j++)
        {
            sum += arr[j];

            mnh.push(sum);

            if (mnh.size() > K)
                mnh.pop();
        }
    }

    return mnh.top();
}