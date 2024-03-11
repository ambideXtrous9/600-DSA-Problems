#include <bits/stdc++.h>

using namespace std;

class RollingMedian
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    RollingMedian()
    {
    }

    void balanceHeap()
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

    void add(int val)
    {
        if (maxheap.empty() or val < maxheap.top())
            maxheap.push(val);
        else
            minheap.push(val);

        balanceHeap();
    }

    double median()
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
};