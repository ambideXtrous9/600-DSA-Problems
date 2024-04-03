#include <bits/stdc++.h>
using namespace std;



bool IsValidPreorder(vector<int> arr)
{
    int n = arr.size();

    stack<int> S;
    int parent = INT_MIN;
    for(int i=0;i<n;i++)
    {
        // curr is greater than S.top()
        while(!S.empty() && S.top()<arr[i])
        {
            parent = S.top();
            S.pop();
        }
        // curr is smaller than S.top()
        if(arr[i]<parent) return false;
        S.push(arr[i]);
    }

    return true;
}