#include <bits/stdc++.h>

using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> V;
    priority_queue<int, vector<int>, greater<int>> mnh;
    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < k; i++)
        {
            mnh.push(arr[i][j]);
        }
        int top = mnh.top();
        V.push_back(top);
        mnh.pop();
    }
    while (!mnh.empty())
    {
        int top = mnh.top();
        V.push_back(top);
        mnh.pop();
    }
    return V;
}