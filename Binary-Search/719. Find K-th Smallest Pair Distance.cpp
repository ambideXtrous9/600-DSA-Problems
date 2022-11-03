#include <bits/stdc++.h>

using namespace std;

bool fun(vector<int> &arr, int k, int dif)
{
    int n = arr.size();

    int pairs = 0;

    int j = 0;

    for (int i = 0; i < n; i++)
    {

        while (j < n && arr[j] - arr[i] <= dif)
            j++;

        pairs += (j - i - 1);
    }

    return pairs >= k;
}
int smallestDistancePair(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int l = 0;
    int r = arr[n - 1];

    while (l <= r)
    {

        int mid = l + (r - l) / 2;

        if (fun(arr, k, mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return l;
}

// TLE

int smallestDistancePair(vector<int> &nums, int k)
{
    priority_queue<int> H;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            H.push(abs(nums[i] - nums[j]));

            if (H.size() > k)
                H.pop();
        }
    }

    return H.top();
}