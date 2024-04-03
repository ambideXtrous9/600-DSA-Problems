#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int num1 = INT_MIN;
    int num2 = INT_MIN;

    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == num1)
            cnt1++;
        else if (nums[i] == num2)
            cnt2++;

        else if (cnt1 == 0)
        {
            num1 = nums[i];
            cnt1 = 1;
        }

        else if (cnt2 == 0)
        {
            num2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> V;
    cnt1 = 0;
    cnt2 = 0;

    for (auto x : nums)
    {
        if (x == num1)
            cnt1++;
        if (x == num2)
            cnt2++;
    }

    if (cnt1 > n / 3)
        V.push_back(num1);
    if (cnt2 > n / 3)
        V.push_back(num2);

    sort(V.begin(), V.end());

    return V;
}

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> M;

    for (auto x : nums)
        M[x]++;

    vector<int> V;

    for (auto x : M)
    {
        if (x.second > (n / 3))
            V.push_back(x.first);
    }

    return V;
}

// Moore's Algo

int majorityElementM(vector<int> &arr)
{
    int candidate = 0, count = 0, n = arr.size();
   
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
        }
        if (arr[i] == candidate)
            count++;
        else
            count--;
    }
    
    return candidate;
}