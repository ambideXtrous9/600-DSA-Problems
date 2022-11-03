#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++)
    {
        V.push_back({price[i], i + 1});
    }
    sort(V.begin(), V.end());
    int ans = 0;
    for (int i = 0; i < n && k > 0; i++)
    {
        int price = V[i].first;
        int quant = V[i].second;
        if (price * quant <= k)
        {
            ans += quant;
            k -= price * quant;
        }
        else
        {
            int frac = k / price;
            ans += frac;
            k -= frac * price;
        }
    }
    return ans;
}