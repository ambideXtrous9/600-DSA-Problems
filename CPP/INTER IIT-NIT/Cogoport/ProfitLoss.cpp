#include <bits/stdc++.h>

using namespace std;

void solve(vector<float> cp, vector<float> ir, vector<float> ir2, int n)
{
    float cost = 0;
    float sell = 0;

    for (int i = 0; i < n; i++)
    {
        cost += cp[i];
        sell += ((cp[i] * (100 + ir[i])) * (100 - ir2[i])) / (100 * 100);
    }

    int res = (sell - cost);

    if (res < 0)
        cout << "Loss " << abs(res) << endl;
    else
        cout << "Profit " << abs(res) << endl;
}

int main()
{
    int n = 3;
    vector<float> cp = {120, 200, 90};
    vector<float> ir = {5, 10, 6};
    vector<float> ir2 = {7, 13, 10};

    solve(cp, ir, ir2, n);
}
