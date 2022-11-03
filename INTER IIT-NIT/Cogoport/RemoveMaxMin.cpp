#include <bits/stdc++.h>

using namespace std;

int func(vector<int> &V)
{
    int n = V.size();
    int res = 0;

    for (auto x : V)
    {
        stack<int> S;
        int t = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        while (x)
        {
            int k = x % 10;
            t = t * 10 + k;
            mn = min(mn, k);
            mx = max(mx, k);
            x /= 10;
        }

        int ans = 0;

        while (t)
        {
            int k = t % 10;
            if (k != mn && k != mx)
            {
                ans = ans * 10 + k;
            }
            t /= 10;
        }
        res += ans;
    }
    cout << res << endl;
    return res;
}
int main()
{
    vector<int> V = {2345, 3567, 3450, 3987};
    func(V);
    return 0;
}
