#include <bits/stdc++.h>

using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    vector<int> ans;

    for (int i = 0; i < n; i++) // O(n)
    {
        pq.push(arr[i]);
    }
    
    for (int i = 0; i < k; i++) // O(klogk)
    {
        int curr = pq.top();
        pq.pop();
        ans.push_back(curr);
    }
    
    return ans;
    // code here
}