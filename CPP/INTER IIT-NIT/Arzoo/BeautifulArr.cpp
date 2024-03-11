#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> A, vector<array<int, 3>> Q)
{
    partial_sum(begin(A), end(A), begin(A));

    for (auto &[k, y, x] : Q)
    {
        int mask = 0;
        
        for (int i = 30; ~i; --i)
        {
            int cnt = 0;
            
            for (int j = k - 1; j < int(A.size()) && (x & 1 << i) == 0; ++j)
            {
                int sum = A[j] - (j < k ? 0 : A[j - k]);

                cnt += (sum & (mask | 1 << i)) == (mask | 1 << i);
            }
            
            if (cnt >= y)
            {
                mask |= 1 << i;
            }
        }
        cout << (mask | x) << ' ';
    }
}