#include <bits/stdc++.h>

using namespace std;

// SW + Max-Heap

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    // your code here
    priority_queue<pair<int, int>> pq;
    
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }

    vector<int> ans;
    
    ans.push_back(pq.top().first);
    
    for (int i = k; i < arr.size(); i++)
    {
        pq.push({arr[i], i});
        while (pq.top().second <= (i - k))
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}

vector<int> max_of_subarrays(vector<int> nums, int n, int k)
{
    vector<int> output;
    int i = 0;
    int j = 0;
    list<int> l;
    while (j < nums.size())
    {
        if (l.empty())
        {
            l.push_back(nums[j]);
        }
        else
        {
            while (!l.empty() && l.back() < nums[j])
                l.pop_back();
            l.push_back(nums[j]);
        }
        if (j - i + 1 < k)
            ++j;
        else if (j - i + 1 == k)
        {
            output.push_back(l.front());
            if (nums[i] == l.front())
                l.pop_front();
            ++i;
            ++j;
        }
    }
    return output;
}