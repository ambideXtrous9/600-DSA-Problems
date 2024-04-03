#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, char>> P;

string frequencySort(string s)
{
    unordered_map<char, pair<int, int>> M;

    priority_queue<P> H;

    int n = s.length();

    int tt = n;

    for (auto x : s)
    {
        if (M.find(x) != M.end())
        {
            M[x].first++;
        }
        else
        {
            M[x].first++;
            M[x].second = tt;
        }
        tt--;
    }

    for (auto x : M)
    {
        H.push({x.second.first, {x.second.second, x.first}});
    }

    string t = "";

    while (!H.empty())
    {
        char c = H.top().second.second;
        int m = H.top().first;
        H.pop();

        while (m)
        {
            t += c;
            m--;
        }
    }

    return t;
}