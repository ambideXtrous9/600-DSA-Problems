#include <bits/stdc++.h>

using namespace std;

void balanceHeap(priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap)
{
    if (maxheap.size() > minheap.size() + 1)
    {
        minheap.push(maxheap.top());
        maxheap.pop();
    }
    else if (minheap.size() > maxheap.size() + 1)
    {
        maxheap.push(minheap.top());
        minheap.pop();
    }
}

void add(int val, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap)
{
    if (maxheap.empty() or val < maxheap.top())
        maxheap.push(val);
    else
        minheap.push(val);

    balanceHeap(maxheap, minheap);
}

int median(priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap)
{
    if (maxheap.size() == minheap.size())
    {
        return (maxheap.top() + minheap.top()) / 2.0;
    }
    else if (maxheap.size() > minheap.size())
    {
        return maxheap.top();
    }
    return minheap.top();
}
int solve(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;

        for (int j = i; j < n; j++)
        {
            add(nums[j], maxheap, minheap);

            if (maxheap.size() > minheap.size())
                ans += maxheap.top();
            else if (minheap.size() > maxheap.size())
                ans += minheap.top();
        }
    }
    return ans;
}
