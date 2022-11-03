#include <bits/stdc++.h>

using namespace std;

// function to find minimun number of classes allotment
int numberOfClasses(vector<int> v1, vector<int> v2, int m, int n)
{
    multimap<int, int> mp;

    for (int i = 0; i < m; i++)
    {
        mp.insert({v1[i], v2[i]});
    }

    for (auto it : mp)
    {
        int s = it.second;

        auto itt = mp.find(s);

        if (itt != mp.end())
        {
            mp.insert({s, itt->second});
        }
    }

    vector<vector<int>> v(n + 1);

    for (auto it : mp)
    {
        v[it.first].push_back(it.second);
        v[it.second].push_back(it.first);
    }

    vector<int> r;

    for (auto it : v)
    {
        r.push_back(it.size());
    }

    int ans = *max_element(r.begin(), r.end());

    return ans;
}

int main()
{
    // taking input values here
    int n, m;
    cin >> n >> m;
    vector<int> v1(m);

    for (int i = 0; i < m; i++)
        cin >> v1[i];

    int m1;
    cin >> m1;
    vector<int> v2(m1);
    for (int i = 0; i < m1; i++)
        cin >> v2[i];

    int ans = numberOfClasses(v1, v2, m, n);

    cout << ans << endl;

    return 0;
}