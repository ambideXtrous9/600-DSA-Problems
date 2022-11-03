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

#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int par, vector<bool> &visited, vector<vector<int>> &adj)
{
    if (visited[i] == true)
    {
        visited[par] = true;
        return;
    }
    for (int j : adj[i])
    {
        dfs(j, i, visited, adj);
    }
}

void solve()
{
    int n, p, projects, temp;
    cin >> n >> p;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        adj[i].push_back(temp);
    }

    vector<bool> visited(n + 1, false);

    visited[0] = true;

    for (int i = 0; i < p; i++)
    {
        cin >> projects;
        dfs(projects, projects, visited, adj);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
            cout << i << " ";
    }
}

int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        um[v[i]]++;
    }

    int pos_sum = 0, neg_sum = 0;

    for (auto &x : um)
    {
        if (x.second == 1)
        {
            if (x.first > 0)
                pos_sum += x.first;
            else
                neg_sum += x.first;
        }
    }
    cout << pos_sum - neg_sum << "\n";
}

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

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int Dijkstra(vector<pi> adj[], int s, unordered_set<int> &M, int n, int m)
{
    vector<int> dist(n, INT_MAX);

    priority_queue<pi, vector<pi>, greater<pi>> Q;

    dist[s] = 0;

    Q.push({dist[s], s});

    int ans = INT_MAX;

    vector<int> vis(n, false);

    while (!Q.empty() && m)
    {
        auto [val, u] = Q.top();
        Q.pop();

        if (vis[u])
            continue;

        if (val != 0 && M.find(u) != M.end())
        {
            ans = min(ans, val);
            m -= 1;
        }

        vis[u] = true;

        for (auto X : adj[u])
        {
            auto [v, w] = X;
            if (!vis[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> node(m);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        node[i] = x;
    }

    vector<pi> adj[n];
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    unordered_set<int> M(node.begin(), node.end());

    int ans = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        int cur = Dijkstra(adj, node[i], M, n, m);
        ans = min(ans, cur);
    }

    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long pow(long long x, long long y, long long m)
{
    x %= m;

    if (x == 0)
        return 0;

    long long res = 1;

    while (y > 0)
    {
        if (y & 1)
            res = ((res % m) * (x % m)) % m;

        y >>= 1;

        x = ((x % m) * (x % m)) % m;
    }

    return res;
}

long long solve(int s, int n, int m)
{
    int mod = 1e9 + 7;
    long long res = pow(s, n, 10);
    res = pow(res, m, mod);
    return res;
}

int main()
{
    cout << solve(2, 2, 1e9 + 7);
}

#include <bits/stdc++.h>
using namespace std;

bool check(char &c1, char &c2)
{
    if (c1 == c2)
    {
        return true;
    }
    if (c1 == 'a' && c2 == 'o')
    {
        return true;
    }
    if (c1 == 'o' && c2 == 'a')
    {
        return true;
    }
    if (c1 == 't' && c2 == 'l')
    {
        return true;
    }
    if (c1 == 'l' && c2 == 't')
    {
        return true;
    }
    return false;
}

bool f(string drawString, string ticket, int i, int j, int k, int flag, vector<vector<vector<vector<int>>>> &dp)
{
    if (j < 0)
        return true;
    if (i < 0)
        return false;

    if (dp[i][j][k][flag] != -1)
        return dp[i][j][k][flag];

    bool ans = false;

    if (check(drawString[i], ticket[j]))
    {
        ans = ans || f(drawString, ticket, i - 1, j - 1, k, 1, dp);
    }
    else if (k > 0 && flag)
    {
        ans = ans || f(drawString, ticket, i - 1, j, k - 1, 1, dp);
    }
    else if (flag)
    {
        ans = ans || f(drawString, ticket, i, j - 1, k, 1, dp);
    }

    if (!flag && drawString.length() >= ticket.length())
    {
        ans = ans || f(drawString, ticket, i - 1, j, k, 0, dp);
    }
    else
    {
        ans = ans || f(drawString, ticket, i, j - 1, k, 0, dp);
    }

    return dp[i][j][k][flag] = ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> tickets(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
    }

    string drawString;
    cin >> drawString;

    int k;
    cin >> k;

    int ans = 0;
    int m = drawString.length();

    for (auto it : tickets)
    {
        int n = it.length();
        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(n, vector<vector<int>>(k + 1, vector<int>(2, -1))));
        if (f(drawString, it, m - 1, n - 1, k, 0, dp))
            ans++;
    }

    cout << ans << endl;

    return 0;
}
