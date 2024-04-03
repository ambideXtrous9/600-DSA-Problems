#include <bits/stdc++.h>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &M)
{

    int n = M.size();
    int m = M[0].size();

    int s = 0;
    int e = m - 1;

    while (s >= 0 && s < n && e >= 0 && e < m)
    {
        int w = s - 1 < 0 ? -1 : M[s - 1][e];
        int x = s + 1 >= n ? -1 : M[s + 1][e];
        int y = e - 1 < 0 ? -1 : M[s][e - 1];
        int z = e + 1 >= m ? -1 : M[s][e + 1];

        int p = max({w, x, y, z});

        if (M[s][e] > p)
            return {s, e};

        else if (p == w)
            s--;
        else if (p == x)
            s++;
        else if (p == y)
            e--;
        else if (p == z)
            e--;
    }

    return {};
}