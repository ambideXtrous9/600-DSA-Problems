#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    int x = 0;
    int y = 0;

    int aa = a;
    int bb = b;

    while (a != 0)
    {
        x += 1;
        a = a / 10;
    }

    while (b != 0)
    {
        y += 1;
        b = b / 10;
    }

    if (x == 0)
        x = 1;
    if (y == 0)
        y = 1;

    y = pow(10, y);
    x = pow(10, x);

    int p = aa * y + bb;
    int q = bb * x + aa;

    return p > q;
}

string solve(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), comp);

    string S = "";

    for (auto a : nums)
        S += to_string(a);

    return S;
}