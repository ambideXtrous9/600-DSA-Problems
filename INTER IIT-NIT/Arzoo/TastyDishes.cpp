#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int tasty(int n,int m,vector<int> &size,vector<int> &taste)
{

    vector<pair<int,int>> V;

    priority_queue<int,vector<int>,greater<int>> Q;

    for(int i = 0;i<n;i++)
    {
        V.push_back({taste[i],size[i]});
    }

    sort(rbegin(V),rend(V));

    int sum = 0;
    int res = 0;

    for(auto &[t,s] : V)
    {
        Q.push(s);

        sum += s;

        if(Q.size() > m)
        {
            sum -= Q.top();
            Q.pop();
        }
        res = max(res,sum*t);
    }

    res = res % mod;

    return res;
}