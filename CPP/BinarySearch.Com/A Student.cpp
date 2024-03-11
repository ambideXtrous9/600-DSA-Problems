#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int solve(vector<int> &deadlines, vector<int> &credits)
{
    vector<pair<int, int>> arr;
    int n = deadlines.size();

    if (n == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        arr.push_back({credits[i], deadlines[i]});
    }

    sort(arr.begin(), arr.end(), comp); // sort by decreasing profit

    vector<bool> vis(n, false);

    int jobcnt = 0;
    int maxprofit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].second); j >= 0; j--)
        {
            if (vis[j])
                continue;
            else
            {
                vis[j] = true;
                maxprofit += arr[i].first;
                // jobcnt++;
                break;
            }
        }
    }
    return maxprofit;
}