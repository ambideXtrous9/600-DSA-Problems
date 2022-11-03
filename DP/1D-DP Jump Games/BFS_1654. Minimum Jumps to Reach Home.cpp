#include <bits/stdc++.h>

using namespace std;

int minimumJumps(vector<int> &forbidden, int a, int b, int x)
{
    map<int, bool> visited;
    int m = 0;

    // mark the forbidden position as visited.
    for (int f : forbidden)
    {
        visited[f] = true;
        m = max(m, f);
    }

    // the trick
    m = a + b + max(m, x);

    // bfs
    queue<pair<int, bool>> Q;
    int level = 0;

    Q.push({0, true});
    visited[0] = true;

    while (!Q.empty())
    {
        int n = Q.size();
        
        while (n--)
        {
            auto [i, forward] = Q.front();
            Q.pop();

            // ending case
            if (i == x)
                return level;

            // check jump backward first
            int ii = i - b;

            if (forward && ii >= 0 && !visited[ii])
            {
                Q.push({ii, false});
                visited[ii] = true;
            }

            // jump forward
            int jj = i + a;

            if (jj <= m && !visited[jj])
            {
                Q.push({jj, true});
                visited[jj] = true;
            }
        }

        level++;
    }

    return -1;
}