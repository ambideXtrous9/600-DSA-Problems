#include <bits/stdc++.h>

using namespace std;


// Merge-intervals

vector<vector<int>> solve(vector<vector<int>> &V, vector<int> &target)
{
    V.push_back(target);

    sort(V.begin(),V.end());

    vector<vector<int>> L;

    int idx = 0;

    for(int i = 1;i<V.size();i++)
    {
        if(V[idx][1] >= V[i][0])
        {
            V[idx][0] = min(V[i][0],V[idx][0]);
            V[idx][1] = max(V[i][1],V[idx][1]);
        }
        else
        {
            L.push_back(V[idx]);
            idx++;
            V[idx] = V[i];
            
        }
    }
    L.push_back(V[idx]);
    return L;
}

vector<vector<int>> solve(vector<vector<int>> &intervals, vector<int> &target)
{
    vector<vector<int>> result;

    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][1] < target[0])
        {
            result.push_back(intervals[i]);
        }

        else if (intervals[i][0] > target[1])
        {
            result.push_back(target);
            target = intervals[i];
        }

        else if (intervals[i][1] >= target[0] || intervals[i][0] <= target[1])
        {
            target[0] = min(intervals[i][0], target[0]);
            target[1] = max(target[1], intervals[i][1]);
        }
    }

    result.push_back(target);
    return result;
}