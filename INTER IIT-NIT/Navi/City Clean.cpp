#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    
    vector<int> arr;
    
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());
    
    int ans = INT_MAX;
    
    for (int i = 0; i <= n - m; i++)
    {        
        if (arr[i] * arr[m - 1 + i] < 0)
        {
            int curr = min(2 * (abs(arr[i])) + arr[m - 1 + i], abs(arr[i]) + 2 * arr[m - 1 + i]);
            ans = min(ans, curr);
        }
        else if (arr[i] == 0 || arr[m - 1 + i] == 0)
        {
            if (arr[i] == 0)
            {
                ans = min(ans, arr[m - 1 + i]);
            }
            else
            {
                ans = min(ans, abs(arr[i]));
            }
        }
        else if (arr[i] < 0)
        {
            ans = min(ans, abs(arr[i]));
        }
        else
        {
            ans = min(ans, arr[m - 1 + i]);
        }
    }
    cout << ans;
}