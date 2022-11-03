#include <bits/stdc++.h>

using namespace std;

// when L -> initialize with -1 =  vector<int> V(n,-1)
// when R -> initialize with n = vector<int> V(n,n)

// stack top will contain next grt/smaller item to current always

// greater -> <=  pop all the smaller than A[i] from satck
// smaller -> >=  pop all the greater than A[i] from stack



void NSL(vector<int> nums)
{
    int n = nums.size();

    stack<pair<int,int>> S;

    vector<int> V(n,-1);  

    for(int i = 0;i<n;i++)
    {
        while(!S.empty() && S.top().first >= nums[i])
        {
            S.pop();
        }

        if(!S.empty()) V[i] = S.top().second;  // index or element as required

        S.push({nums[i],i});

    }
}

void NSR(vector<int> nums)
{
    int n = nums.size();

    stack<pair<int,int>> S;

    vector<int> V(n,n);

    for(int i = n-1;i>=0;i--)
    {
        while(!S.empty() && S.top().first >= nums[i])
        {
            S.pop();
        }

        if(!S.empty()) V[i] = S.top().second;  // index or element as required

        S.push({nums[i],i});

    }
}

void NGL(vector<int> nums)
{
    int n = nums.size();

    stack<pair<int,int>> S;

    vector<int> V(n,-1);

    for(int i = 0;i<n;i++)
    {
        while(!S.empty() && S.top().first <= nums[i])
        {
            S.pop();
        }

        if(!S.empty()) V[i] = S.top().second;  // index or element as required

        S.push({nums[i],i});

    }
}

void NGR(vector<int> nums)
{
    int n = nums.size();

    stack<pair<int,int>> S;

    vector<int> V(n,n);

    for(int i = n-1;i>=0;i--)
    {
        while(!S.empty() && S.top().first <= nums[i])
        {
            S.pop();
        }

        if(!S.empty()) V[i] = S.top().second;  // index or element as required

        S.push({nums[i],i});

    }
}