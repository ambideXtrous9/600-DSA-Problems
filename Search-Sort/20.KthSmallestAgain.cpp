#include <bits/stdc++.h>

#define int long long int

using namespace std;

int32_t main()
{

    int t;

    cin >> t;

    while (t--)
    {

        int n, q;

        cin >> n >> q;

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {

            int a, b;

            cin >> a >> b;

            v.push_back({a, b});
        }

        sort(v.begin(), v.end());  // 1. sort based first val

        int idx = 0;                // 2. merge intervals

        for (int i = 1; i < v.size(); i++)
        {

            if (v[idx].second >= v[i].first)

                v[idx].second = max(v[idx].second, v[i].second);

            else
            {

                idx++;

                v[idx] = v[i];
            }
        }

        while (q--)
        {

            int k;

            cin >> k;

            int ans = -1;

            for (int i = 0; i <= idx; i++)  // 3. find
            {

                if ((v[i].second - v[i].first + 1) >= k)
                {

                    ans = v[i].first + k - 1;

                    break;
                }

                else
                {

                    k = k - (v[i].second - v[i].first + 1);
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}