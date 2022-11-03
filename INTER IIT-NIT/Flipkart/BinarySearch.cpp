#include <bits/stdc++.h>

using namespace std;

bool ok(int mid, int k, vector<int> &v)
{
    int cnt = 0;
    for (auto x : v)
    {
        cnt += (x + mid - 1) / mid;
    }
    return cnt <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    int ans = 0, left = 0, right = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        ans = max(ans, v[i]);
    }

    right = ans;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (ok(mid, k, v))
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << ans << "\n";
}