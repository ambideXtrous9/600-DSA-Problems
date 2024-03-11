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
