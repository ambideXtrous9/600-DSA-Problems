#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g, up;

vector<int> in, out;

int timer = 0, lg;

void dfs(int u, int p = 0)
{
    in[u] = timer++;
    up[u][0] = p;
    for (int i = 1; i <= lg; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u])
        if (v != p)
            dfs(v, u);
    out[u] = timer++;
}

bool is_ancestor(int u, int v)
{
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = lg; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

class SumSegmentTree
{
    int n;
    vector<int> t;

public:
    SumSegmentTree(int n)
    {
        this->n = n;
        t.resize(4 * n);
    }

    void update(int v, int tl, int tr, int pos, int val)
    {
        if (tl == tr)
            t[v] = val;
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    void update(int pos, int val)
    {
        update(1, 0, n - 1, pos, val);
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
vector<int> solve(int n, vector<int> p, vector<vector<int>> e, int q, vector<vector<int>> c)
{
    g.resize(n);
    in.resize(n);
    out.resize(n);
    int lg = 1 + log2(n);
    up.resize(n, vector<int>(lg, 0));
    for (auto &i : e)
    {
        int u = i[0] - 1, v = i[1] - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    SumSegmentTree st(n << 1);
    vector<tuple<int, int, int, int>> a(n);
    for (int i = 0; i < n; i++)
        a.push_back({p[i], 0, i, i});
    for (int i = 0; i < q; i++)
        a.push_back({c[i][2], i + 1, c[i][0] - 1, c[i][1] - 1});

    sort(a.begin(), a.end());
    vector<int> res(q);

    int pos, type, u, v;
    for (int i = 0; i < a.size(); i++)
    {
        tie(pos, type, u, v) = a[i];
        if (type == 0)
        {
            st.update(in[u], 1);
            st.update(out[u], -1);
        }
        else
        {
            int l = lca(u, v);
            int ans = 0;
            ans += st.query(in[l], in[u]);
            ans += st.query(in[l], in[v]);
            ans -= st.query(in[l], in[l]);
            res[type - 1] = ans;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<vector<int>> e(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        e[i].resize(2);
        cin >> e[i][0] >> e[i][1];
    }
    int q;
    cin >> q;
    vector<vector<int>> c(q);
    for (int i = 0; i < q; i++)
    {
        c[i].resize(3);
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }
    auto res = solve(n, p, e, q, c);
    for (auto &i : res)
        cout << i << endl;
}