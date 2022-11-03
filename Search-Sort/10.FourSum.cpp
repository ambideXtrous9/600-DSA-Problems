#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    vector<vector<int>> res;
    int n = arr.size();

    if (arr.empty())
        return res;

    sort(arr.begin(), arr.end());
    int target;

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int front = j + 1;
            int back = n - 1;

            while (front < back)
            {

                target = k - arr[i] - arr[j];
                if (arr[front] + arr[back] < target)
                    front++;
                else if (arr[front] + arr[back] > target)
                    back--;
                else
                {
                    vector<int> quad(4, 0);
                    quad[0] = arr[i];
                    quad[1] = arr[j];
                    quad[2] = arr[front];
                    quad[3] = arr[back];
                    res.push_back(quad);

                    while (front < back && arr[front] == quad[2])
                        front++;
                    while (front < back && arr[back] == quad[3])
                        back--;
                }
            }
            while (j < n - 2 && arr[j] == arr[j + 1])
                j++;
        }
        while (i < n - 3 && arr[i] == arr[i + 1])
            i++;
    }
    return res;
}

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    // Your code goes here
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int start = j + 1;
            int end = n - 1;
            while (start < end)
            {
                int sum = arr[i] + arr[j] + arr[start] + arr[end];
                if (sum == k)
                {
                    s.insert({arr[i], arr[j], arr[start], arr[end]});
                    start++;
                    end--;
                }
                else if (sum > k)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }
    for (auto i : s)
    {
        ans.push_back(i);
    }
    return ans;
}