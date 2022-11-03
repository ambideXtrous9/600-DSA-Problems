#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &x, vector<int> &type)
{

    int N = x.size();

    int sum = 1;
    int ans = 0;

    priority_queue<int> q;

    for (int i = 0; i < N; i++)
    {
        if (type[i] == 1)
        {
            q.push(x[i]);
        }
        else if (type[i] == 2)
        {
            while (!q.empty() && sum <= x[i])
            {
                // We are splitting any heroes to some heroes that's why "-1" ex.
                // intial heroes 3 now splitting 1 hero to 4 new
                // hero so: 2+1 (before) ->>>> 2+4 (after)
                sum += q.top() - 1;
                q.pop();
                ans++;
            }

            if (sum <= x[i] && q.empty()) // gather all heroes still smaller than that cell then impossible
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}