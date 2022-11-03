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
