#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &INV)
{
    vector<vector<int>> MI;
    sort(INV.begin(), INV.end()); // sort based on start values of intervals

    vector<int> temp = INV[0]; 

    int idx = 0;

    for (auto cur : INV)
    {
        if (cur[0] <= temp[1])
        {
            temp[1] = max(cur[1], temp[1]);
        }
        else
        {
            idx++;
            MI.push_back(temp);
            temp = cur;
        }
    }
    MI.push_back(temp);
    return MI;
}

int MergeIntervals(vector<vector<int>> &V)
{

    int n = V.size();

    if (n == 0)
        return 0;

    sort(V.begin(), V.end());

    int idx = 0;

    int count = 0;

    for (int i = 1; i < V.size(); i++)
    {
        if (V[idx][1] >= V[i][0])
        {
            V[idx][0] = min(V[i][0], V[idx][0]);
            V[idx][1] = max(V[i][1], V[idx][1]);
        }
        else
        {
            idx++;
            V[idx] = V[i];
        }
    }

    int ans = 0;

    for (int i = 0; i <= idx; i++)
    {
        cout << V[i][0] << "," << V[i][1] << endl;
    }

    return ans;
}