#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> loc, vector<int> movefrom, vector<int> moveto)
{
    int n = loc.size();
    int m = movefrom.size();

    set<int> S;

    for (auto x : loc)
        S.insert(x);

    for (int i = 0; i < m; i++)
    {
        S.erase(movefrom[i]);
        S.insert(moveto[i]);
    }

    vector<int> V(S.begin(), S.end());

    return V;
}