#include <bits/stdc++.h>

using namespace std;

/*
Algo:
We greedily place parcels with lower cost that are not present in truck
to rech upto its capacity k.
*/

int ShippingCost(vector<int> &nums, int k)
{

    int n = nums.size();
    int t = k - n;

    unordered_set<int> S(nums.begin(), nums.end());

    int item = 1;
    int count = 0;
    int cost = 0;

    while (count < t)
    {
        if (S.find(item) == S.end())
        {
            cost += item;
            count++;
        }
        item++;
    }

    return cost;
}