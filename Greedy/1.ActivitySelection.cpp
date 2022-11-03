#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({end[i], start[i]});
    }
    int ans = 1;
    sort(v.begin(), v.end());
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (v[j].second > v[i].first)
        {
            ans++;
            i = j;
        }
    }
    return ans;
}