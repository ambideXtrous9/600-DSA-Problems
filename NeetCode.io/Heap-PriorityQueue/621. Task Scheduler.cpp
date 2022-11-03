#include <bits/stdc++.h>

using namespace std;

int leastInterval(vector<char> &tasks, int k)
{
    // k is the wait time between 2 same tasks

    unordered_map<char, int> hash;
    for (int i = 0; i < tasks.size(); i++)
        hash[tasks[i]]++;

    priority_queue<int> pq; // max heap

    for (auto it : hash)
        pq.push(it.second);

    int timer = 0;

    while (!pq.empty())
    {
        vector<int> temp;

        for (int i = 0; i <= k; i++) // block of size (k+1)
        { 
            if (!pq.empty())
            {
                temp.push_back(pq.top()); // pick frequently occuring tasks (greedy)
                pq.pop();
            }
        }

        for (int i = 0; i < temp.size(); i++)
        {
            if (--temp[i] > 0)
                pq.push(temp[i]); //(if tasks of the kind remain push them back in)
        }

        // if queue is empty then we got no remaining tasks hence the current block size
        // is temp.size() else we got a block of size k+1

        timer += pq.empty() ? temp.size() : k + 1; 
    }
    return timer;
}

//By observing a few test cases, we know that it's a lot easier to start from the task with the highest frequency of occurrence. Let's say the task is A.
//Then we can put all A tasks into the array, and make sure they are separated by n idle inervals.
//A____A____A____A____A____A

// number of A = num(A)            // the number of task A
// gap = (num(A) - 1) x n          // the number of idle intervals
// total length = num(A) + gap     // the total length

int leastInterval(vector<char> &tasks, int n)
{
    int len = tasks.size();
    unordered_map<char, int> mp;
    int count = 0;
    for (auto e : tasks)
    {
        mp[e]++;
        count = max(count, mp[e]);
    }

    int ans = (count - 1) * (n + 1);
    
    for (auto e : mp)
        if (e.second == count)
            ans++;
    
    return max(len, ans);
}