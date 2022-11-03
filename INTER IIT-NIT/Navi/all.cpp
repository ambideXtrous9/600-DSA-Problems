#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; // number of test cases
    cin >> t;

    while (t--)
    {
        int k, n;

        cin >> k >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int dp[n + 1][2][k + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int flag = 1; flag >= 0; flag--)
            {
                for (int j = 1; j <= k; j++)
                {
                    int cost = dp[i + 1][flag][j];

                    if (flag && j)
                    {
                        cost = max(cost, -arr[i] + dp[i + 1][!flag][j]);
                    }
                    else
                    {
                        cost = max(cost, arr[i] + dp[i + 1][!flag][j - 1]);
                    }

                    dp[i][flag][j] = cost;
                }
            }
        }

        return dp[0][1][k];
    }
}

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

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; // number of test cases
    cin >> t;

    while (t--)
    {
        int n; // taking input
        cin >> n;

        if (n == 1 || n == 2)
            cout << "1" << endl;

        else if (n == 3)
            cout << "2" << endl;

        else
        {
            vector<int> dp(n + 1, 0);

            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;
            dp[3] = 2;

            for (int i = 4; i <= n; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 3];
            }

            cout << dp[n] << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

// function to find minimun number of classes allotment
int numberOfClasses(vector<int> v1, vector<int> v2, int m, int n)
{
    multimap<int, int> mp;

    for (int i = 0; i < m; i++)
    {
        mp.insert({v1[i], v2[i]});
    }

    for (auto it : mp)
    {
        int s = it.second;

        auto itt = mp.find(s);

        if (itt != mp.end())
        {
            mp.insert({s, itt->second});
        }
    }

    vector<vector<int>> v(n + 1);

    for (auto it : mp)
    {
        v[it.first].push_back(it.second);
        v[it.second].push_back(it.first);
    }

    vector<int> r;

    for (auto it : v)
    {
        r.push_back(it.size());
    }

    int ans = *max_element(r.begin(), r.end());

    return ans;
}

int main()
{
    // taking input values here
    int n, m;
    cin >> n >> m;
    vector<int> v1(m);

    for (int i = 0; i < m; i++)
        cin >> v1[i];

    int m1;
    cin >> m1;
    vector<int> v2(m1);
    for (int i = 0; i < m1; i++)
        cin >> v2[i];

    int ans = numberOfClasses(v1, v2, m, n);

    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int f(int i, int p, int mx, int n, int k, vector<int> &a, vector<vector<int>> &dp)
{
    if (p == k)
        return mx;

    int remaining = (n - i) >> 1;

    if (p + remaining < k)
        return 1e9;

    if (i >= n - 1)
        return 1e9;

    if (dp[i][p] != -1)
        return dp[i][p];
    // we can take or not

    int ans = f(i + 1, p, mx, n, k, a, dp);

    ans = min(ans, f(i + 2, p + 1, max(mx, a[i + 1] - a[i]), n, k, a, dp));

    return dp[i][p] = ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<vector<int>> dp(n, vector<int>(k, -1));

    cout << f(0, 0, 0, n, k, a, dp);
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string ans = "";

    unordered_map<char, char> M;
    int idx = 0;

    for (auto c : str)
    {
        if (M.find(c) == M.end())
        {
            M[c] = char('A' + idx);
            ans += M[c];
            idx++;
        }
        else
            ans += M[c];
    }

    cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int color, vector<bool> &visited, int i, int &count, int arr[])
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (!visited[x] && arr[x] == color)
        {
            ++count;
            dfs(adj, color, visited, x, count, arr);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n + 1];
    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];

    vector<int> adj[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n + 1, false);

    int res = 1;

    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            int count = 1;
            dfs(adj, arr[i], visited, i, count, arr);
            res = max(res, count);
        }
    }
    cout << res;
}

int dfs(int idx, vector<vector<int>> &graph, vector<bool> &visited, int color, vector<int> &colors)
{
    visited[idx] = true;
    int cnt = 0;

    for (auto it : graph[idx])
    {
        if (!visited[it] && colors[it] == color)
            cnt += dfs(it, graph, visited, color, colors);
    }
    return cnt + 1;
}

#include <bits/stdc++.h>

using namespace std;
/*
concept is as follows -
basically after all the edges are removed you will get some sort of forest you can
calculate the size of max component of that forest and then add edge and compute the size and soo on.
Just keep on saving the output and print them in a reverse order.
*/

vector<int> parent, sz;

int Get(int x)
{
    return parent[x] == x ? x : Get(parent[x]);
}

void Union(int x, int y)
{
    x = Get(x);
    y = Get(y);

    if (x != y)
    {
        if (sz[x] < sz[y])
            swap(x, y);

        parent[y] = x;

        sz[x] += sz[y];
    }
}
void solve()
{
    parent.clear();
    sz.clear();

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1, 0);
    sz.resize(n + 1, 1);

    iota(parent.begin(), parent.end(), 0);

    vector<int> from(m), to(m), visited(m, true);

    for (int i = 0; i < m; i++)
        cin >> from[i];

    for (int i = 0; i < m; i++)
        cin >> to[i];

    int q;
    cin >> q;
    vector<int> query(q);

    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
        query[i]--;
        visited[query[i]] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        if (visited[i])
            Union(from[i], to[i]);
    }

    vector<int> ans(q);

    for (int i = q - 1; i >= 0; i--)
    {
        ans[i] = *max_element(sz.begin(), sz.end());
        Union(from[query[i]], to[query[i]]);
        visited[i] = 1;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}

int main()
{
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, vector<int>> mp;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]].push_back(i);
    }
    // Push char index in array
    // Then for each char take vec size and if even mark mid and mid-1 as -1 and for odd size mark mid as -1 and push the temp array to mp[ch]. Then push all index where ele is not -1 to arr and then sort and in string push all the char  from string to res string.

    for (auto x : mp)
    {
        vector<int> temp = x.second;
        char ch = x.first;

        int n = temp.size();

        if (n % 2 == 0)
        {
            int mid = n / 2;
            temp[mid] = -1;
            temp[mid - 1] = -1;
        }
        else
        {
            temp[n / 2] = -1;
        }
        mp[ch] = temp;
    }

    vector<int> in;

    for (auto x : mp)
    {
        for (int i = 0; i < x.second.size(); i++)
        {
            if (x.second[i] != -1)
                in.push_back(x.second[i]);
        }
    }

    sort(in.begin(), in.end());

    string res;
    for (int i = 0; i < in.size(); i++)
    {
        res.push_back(s[in[i]]);
    }
    cout << res;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int d = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] > d)
            {
                d = a[i];
            }
            // if first soldier is the last soldier
            if (i == n - 1 && l - a[i] > d)
            {
                d = l - a[i];
            }
            // if more soldier are after him
            else
            {
                int x = ceil((float)(a[i + 1] - a[i]) / (float)2);
                d = max(x, d);
            }
        }
        else if (i == n - 1)
        {
            d = max(d, l - a[i]);
        }
        else
        { // for intermediate soldier
            int x = ceil((float)(a[i + 1] - a[i]) / (float)2);
            d = max(x, d);
        }
    }
    cout << d;
}
