#include <bits/stdc++.h>

using namespace std;

int solve(int R, int W, int X, int Y, int Z)
{
    int n = (W + Y + Z - X - 4 * R) / 13;
    return max(0, (n - R));
}