#include <bits/stdc++.h>

using namespace std;

typedef vector<int> V;

int minimumEffortPath(vector<vector<int>> &H)
{

    int n = H.size();
    int m = H[0].size();

    priority_queue<V, vector<V>, greater<V>> Q;

    Q.push({0, 0, 0});

    int ans = 0;

    vector<int> dir = {0, 1, 0, -1, 0};

    while (!Q.empty())
    {
        auto X = Q.top();

        int w = X[0];
        int u = X[1];
        int v = X[2];

        Q.pop();

        if (H[u][v] == -1)
            continue;

        ans = max(ans, w);

        if (u == n - 1 && v == m - 1)
            return ans; // reached the dest

        for (int i = 0; i < 4; i++)
        {
            int x = u + dir[i];
            int y = v + dir[i + 1];

            if (x < 0 || y < 0 || x >= n || y >= m || H[x][y] == -1)
                continue; // OFB or  already visited

            int dist = abs(H[u][v] - H[x][y]); // absolute dist

            Q.push({dist, x, y});
        }

        H[u][v] = -1; // node visited
    }

    return ans;
}