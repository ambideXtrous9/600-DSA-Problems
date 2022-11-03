#include <iostream>

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr)
{

    int N = arr.size();

    int maxi = INT_MIN;

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        maxi = max(arr[i], maxi);
        sum += arr[i];
    }

    if (maxi > ((sum + 1) / 2))
    {

        int remain = (sum - maxi);
        return remain * 2 + 1;
    }

    return sum;
}

int main()
{

    int N;
    cin >> N;

    vector<int> arr(N, -1);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr);
    return 0;
}