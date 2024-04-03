#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{

    int lm = 0;
    int gm = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        lm = lm + nums[i];

        gm = max(gm, lm);

        if (lm < 0)
            lm = 0;
    }

    return gm;
}