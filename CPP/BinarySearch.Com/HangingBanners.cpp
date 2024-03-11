#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a.back() < b.back();
}

int solve(vector<vector<int>> &V)
{
    int n = V.size();

    if (n <= 1)
        return n;

    sort(V.begin(), V.end(), comp);

    int idx = 0;
    int count = 1;

    for (int i = 1; i < V.size(); i++)
    {
        if (V[idx][1] >= V[i][0])
        {
            continue;
        }
        else
        {
            idx = i;
            count++;
        }
    }
    return count;
}

int solve(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return 0;

    sort(intervals.begin(), intervals.end());

    int count = 1;
    int l = intervals[0][1];
    
    for (int i = 1; i < intervals.size(); i++)
    {
        if (l >= intervals[i][0])
        {
            l = min(intervals[i][1], l);
        }
        else
        {
            count++;
            l = intervals[i][1];
        }
    }
    return count;
}