#include <bits/stdc++.h>

using namespace std;

int kadanes(vector<int> arr)
{
    int gm = INT_MIN;
    int lm = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        lm += arr[i];
        gm = max(gm, lm);
        if (lm < 0)
            lm = 0;
    }
    return gm;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int mx = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        vector<int> v(C, 0);
        for (int i1 = i; i1 < R; i1++)
        {
            for (int j = 0; j < C; j++)
            {
                v[j] += M[i1][j];
            }
            mx = max(mx, kadanes(v));
        }
    }
    return (mx);
}