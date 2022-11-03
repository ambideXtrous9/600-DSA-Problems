#include <bits/stdc++.h>

using namespace std;

string rearrangeString(string str)
{
    unordered_map<char, int> freq;
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

string reorganizeString(string s)
{
    unordered_map<char, int> M;

    priority_queue<pair<int, char>> H; // Max-Heap with freq and char

    string R;

    for (auto &c : s)
    {
        M[c]++;
    }

    for (auto &it : M)
    {
        H.push({it.second, it.first});
    }

    while (H.size() > 1)
    {
        char top1 = H.top().second;
        H.pop();
        char top2 = H.top().second;
        H.pop();

        R += top1;
        R += top2;

        if (M[top1] > 1)
        {
            M[top1]--;
            H.push({M[top1], top1});
        }
        if (M[top2] > 1)
        {
            M[top2]--;
            H.push({M[top2], top2});
        }
    }
    if (!H.empty())
    {
        char last = H.top().second;
        if (M[last] > 1)
            return "";
        else
            R += last;
    }
    return R;
}