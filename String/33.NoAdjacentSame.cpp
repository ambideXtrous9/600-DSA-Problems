#include <bits/stdc++.h>
using namespace std;

string rearrangeString(string str)
{
    // code here

    unordered_map<char, int> freq;
    // max-heap
    priority_queue<pair<int, char>> max_heap;
    for (auto x : str)
        freq[x]++;

    for (auto it : freq)
        max_heap.push({it.second, it.first});

    str = "";
    while (max_heap.size() > 1)
    {
        auto top1 = max_heap.top();
        max_heap.pop();
        auto top2 = max_heap.top();
        max_heap.pop();

        str += top1.second;
        str += top2.second;

        if (--top1.first > 0)
            max_heap.push(top1);
        if (--top2.first > 0)
            max_heap.push(top2);
    }

    if (max_heap.size())
    {
        if (max_heap.top().first == 1)
            str += max_heap.top().second;
        else
            return "-1";
    }

    return str;
}