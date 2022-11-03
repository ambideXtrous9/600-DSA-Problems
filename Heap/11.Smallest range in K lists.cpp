#include <bits/stdc++.h>

using namespace std;


/*
we have to make a pririty queue to store the index ,row_number and element also.
travese the lists and keep on finding the min and max difference .
if range of previous difference is greater than current min max difference ,update range.
*/

typedef pair<int,pair<int,int>> pi;

#define N 1000

pair<int, int> findSmallestRange(int nums[][N], int n, int k)
{
    priority_queue<pi, vector<pi>, greater<pi>> H;
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        mn = min(mn, nums[i][0]);
        mx = max(mx, nums[i][0]);
        H.push({nums[i][0], {i, 0}});
    }

    int a = mn;
    int b = mx;

    while (!H.empty())
    {
        pi temp = H.top();
        H.pop();

        if (temp.second.second + 1 < n)
        {
            int r = temp.second.first;
            int c = temp.second.second + 1;

            H.push({nums[r][c], {r, c}});

            mn = H.top().first;
            mx = max(mx, nums[r][c]);
            if (b - a > mx - mn)
            {
                a = mn;
                b = mx;
            }
        }
        else
            break;
    }

    return {a, b};
}