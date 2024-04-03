#include <bits/stdc++.h>

using namespace std;

int Solve(vector<int> const &A, int n, int k)
{
    vector<vector<int>> d(n + 1, vector<int>(k + 1));
    
    for (int i = 0; i <= n; ++i)
    {
        for (int k0 = 0; k0 <= k; ++k0)
        {
            int rmin = INT_MAX;

            for (int j = 0; j <= k0; ++j)
            {
                int r = 0;
                
                if (i - 1 - j < 0)
                    r = 0;
                
                else if (i >= n)
                    r = d[i - 1 - j][k0 - j];
                
                else
                {
                    int step = (abs(A[i] - A[i - 1 - j]) + j) / (j + 1);
                    int prev = d[i - 1 - j][k0 - j];
                    r = max(step, prev);
                }
                
                rmin = min(rmin, r);
            }

            d[i][k0] = rmin;
        }
    }
    return d[n][k];
}