#include <bits/stdc++.h>

using namespace std;

void solve(pair<string, int> &p, unordered_set<string> &s, map<char, set<int>> &mp)
{
    string temp = p.first;
    if (s.find(temp) != s.end())
    {
        if (mp[temp[0]].find(p.second) != mp[temp[0]].end())
        {
            int val = p.second;
            // cout<<val;
            mp[temp[0]].erase(val);
            mp[temp[1]].insert(val);
        }
    }
}
int main()
{
    unordered_set<string> s{"AB", "BC", "CE", "CD", "CB", "DB"};
    map<char, set<int>> mp;
    // n number of ID's and M number of queries;
    int n, m;
    n = 10;
    vector<pair<string, int>> v;
    mp['A'] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    mp['B'] = {};
    mp['C'] = {};
    mp['D'] = {};
    mp['E'] = {};
    m = 11;
    while (m--)
    {
        string query;
        int id;
        // write query in the format "SD x" where S-source,D-Destination , x-id
        cin >> query >> id;

        v.push_back({query, id});
    }
    for (auto it : v)
    {
        solve(it, s, mp);
    }
    for (auto it : mp)
    {
        cout << it.first << " :";
        for (auto x : it.second)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
