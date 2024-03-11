#include <bits/stdc++.h>

using namespace std;


// triplet sum to 0

vector<vector<int>> threeSum(vector<int> &num)
{
    vector<vector<int>> res;

    sort(num.begin(), num.end());

    // moves for a
    for (int i = 0; i < (int)(num.size()) - 2; i++)
    {

        if (i == 0 || (i > 0 && num[i] != num[i - 1]))
        {

            int lo = i + 1;

            int hi = (int)(num.size()) - 1;

            int sum = 0 - num[i];

            while (lo < hi)
            {
                if (num[lo] + num[hi] == sum)
                {

                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[lo]);
                    temp.push_back(num[hi]);
                    res.push_back(temp);

                    while (lo < hi && num[lo] == num[lo + 1])
                        lo++;
                    while (lo < hi && num[hi] == num[hi - 1])
                        hi--;

                    lo++;
                    hi--;
                }
                else if (num[lo] + num[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return res;
}

long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr, arr + n);
    long long count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] < sum)
            {
                count += (r - l);
                l++;
            }
            else
                r--;
        }
    }

    return count;
}