#include <bits/stdc++.h>

using namespace std;

int kthSmallest(int arr[], int N, int K)
{
 
    // For finding min element we need (Max heap)priority
    // queue
    priority_queue<int> pq;
 
    for (int i = 0; i < N; i++) 
    {
        pq.push(arr[i]);

        if(pq.size()>K)
        {
            pq.pop();
        }
    }

    // Return top of element
    return pq.top();
}

int kthGreatest(int arr[], int N, int K)
{
 
    // For finding min element we need (Max heap)priority
    // queue
    priority_queue<int,vector<int>,greater<int>> pq;
 
    for (int i = 0; i < N; i++) 
    {
        pq.push(arr[i]);

        if(pq.size()>K)
        {
            pq.pop();
        }
    }
    
    // Return top of element
    return pq.top();
}