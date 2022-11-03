#include <bits/stdc++.h>

using namespace std;


// GFG - IPL 2021 - Match Day 2

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> output;

    int i = 0;
    int j = 0;

    deque<int> l;

    while (j < nums.size())
    {
        if (l.empty())
        {
            l.push_back(nums[j]);
        }

        else
        {
            while (!l.empty() && l.back() < nums[j])
            {
                l.pop_back();
            }

            l.push_back(nums[j]);
        }

        if (j - i + 1 < k)
        {
            j++;
        }

        else // == k
        {
            output.push_back(l.front());
            if (nums[i] == l.front())
            {
                l.pop_front();
            }

            i++;
            j++;
        }
    }
    return output;
}