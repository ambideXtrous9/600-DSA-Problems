#include <bits/stdc++.h>

using namespace std;

bool subArrayExists(int arr[], int n)
{
    int sum = 0;
    int flag = 0;

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || m[sum] || arr[i] == 0)
        {
            flag = 1;
            break;
        }
        else
            m[sum] = 1;
    }
    if (flag == 1)
    {
        return 1;
    }
    else
        return 0;
}