#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &nums)
{
    int n = nums.size();
    stack<int> S;
    int turns = 0;

    for (auto x : nums)
    {
        if (!S.empty() && S.top() == x)
        {
            S.pop();
            turns++;
        }
        else
        {
            S.push(x);
        }
    }

    return turns & 1;  // if I win -> turn will be odd else even
}