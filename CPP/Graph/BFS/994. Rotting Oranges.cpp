#include <bits/stdc++.h>

using namespace std;


/*

1. Multi Source BFS.

2. At every level of Queue : increment the Timer (start the timer before)

3. at the end we have to recheck whether any good ornage is left.

4. If exist then  return -1

5. Other wise return (Timer-1)


*/

int orangesRotting(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();

    queue<pair<int, int>> Q;

    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
                flag = true;

            if (M[i][j] == 2)
                Q.push({i, j});
        }
    }

    vector<int> dir = {0, 1, 0, -1, 0};

    if (!flag)
        return 0;

    int count = 0;

    while (!Q.empty())
    {
        count++;

        int cnt = Q.size();

        for (int k = 0; k < cnt; k++)
        {
            int u = Q.front().first;
            int v = Q.front().second;

            Q.pop();

            for (int i = 0; i < 4; i++)
            {
                int p = u + dir[i];
                int q = v + dir[i + 1];

                if (p < 0 || q < 0 || p >= n || q >= m || M[p][q] == 0 || M[p][q] == 2)
                    continue;

                else
                {
                    M[p][q] = 2;

                    Q.push({p, q});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
                return -1;
        }
    }

    return count - 1;
}