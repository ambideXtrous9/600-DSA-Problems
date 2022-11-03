#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dist;

struct st
{
    int u;
    int v;
    int d;
};
struct comp
{
    bool operator()(st s1, st s2)
    {
        int d1 = s1.d, d2 = s2.d;
        return d1 >= d2;
    }
};
int shop(int n, int k, vector<string> centers, vector<vector<int>> roads)
{
    dist.assign(n, vector<int>(1 << k, INT_MAX));
    
    int mask = 0;
    vector<int> avail(n, 0);

    for (int i = 0; i < n; i++)
    {
        stringstream ss;
        ss << centers[i];
        int num;
        int cnt = 0;
        while (ss >> num)
        {
            cnt++;
            if (cnt == 1)
                continue;
            avail[i] = avail[i] | (1 << (num - 1));
        }
    }
    mask = avail[0];

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0] - 1;
        int v = roads[i][1] - 1;
        int w = roads[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<st, vector<st>, comp> pq;
    
    dist[0][mask] = 0;
    pq.push({0, mask, 0});

    while (!pq.empty())
    {
        int node = pq.top().u;
        mask = pq.top().v;
        int d = pq.top().d;
        pq.pop();
        
        if (d != dist[node][mask])
            continue;
        
        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (dist[node][mask] != INT_MAX && dist[v][avail[v] | mask] > dist[node][mask] + w)
            {
                dist[v][avail[v] | mask] = dist[node][mask] + w;
                pq.push({v, avail[v] | mask, dist[v][avail[v] | mask]});
            }
        }
    }

    int ans = INT_MAX; // final answer
    for (int i = 0; i < (1 << k); i++)
    {
        for (int j = 0; j < (1 << k); j++)
        {
            if ((i | j) == (1 << k) - 1)
                ans = min(ans, max(dist[n - 1][i], dist[n - 1][j]));
        }
    }
    return ans;
}

#define N 1025
#define oo 1234567890

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<pair<int, int>> road[N];
priority_queue<iii, vector<iii>, greater<iii>> Q;

int n, m, k, ans, fish[N], dis[N][N];

void dijkstra()
{
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < (1 << k); ++j)
            dis[i][j] = oo;
    
    Q.push(iii(0, ii(1, fish[1])));
    dis[1][fish[1]] = 0;
    // dis[i][state] : smallest weights to achieve state at node i

    while (Q.size())
    {
        // st : state   nst : new state   u,v : node   du, uv : weight
        int u = Q.top().second.first,
            du = Q.top().first,
            st = Q.top().second.second;
        Q.pop();

        if (du != dis[u][st])
            continue;

        for (auto i : road[u])
        {
            int v = i.second,
                uv = i.first,
                nst = st | fish[v];
            if (dis[v][nst] > uv + du)
            {
                dis[v][nst] = uv + du;
                Q.push(iii(dis[v][nst], ii(v, nst)));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        int t, x;
        fish[i] = 0;
        cin >> t;
        while (t--)
        {
            cin >> x;
            fish[i] |= (1 << (x - 1));
            /*fish[i] : represent types of fish at node i by bitmask technique
                        we call this as a state */
        }
    }
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        road[u].push_back(make_pair(w, v));
        road[v].push_back(make_pair(w, u));
    }

    dijkstra();

    ans = oo;
    for (int i = 0; i < (1 << k); ++i)
        for (int j = i; j < (1 << k); ++j)
            if ((i | j) == (1 << k) - 1) // means achieve state 11...111(k times)
                ans = min(ans, max(dis[n][i], dis[n][j]));
    cout << ans;
    return 0;
}