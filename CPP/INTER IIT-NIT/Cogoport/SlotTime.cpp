#include <bits/stdc++.h>

using namespace std;


// tick no + slot no

static bool comp(pair<int,int> &a,pair<int,int> &b)
{
    if(a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}

void solve(vector<pair<int,int>> &arr)
{

    sort(arr.begin(),arr.end(),comp);

    for(int i = 0;i<arr.size();i++)
    {
        cout<<arr[i].first<<" ";
    }

}

int main()
{
    vector<pair<int,int>> V = {{2,3},{4,1},{6,4},{5,2},{1,3},{7,3},{3,2}};

    solve(V);

    return 0;
}