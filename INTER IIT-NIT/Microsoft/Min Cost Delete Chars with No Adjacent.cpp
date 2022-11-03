#include <bits/stdc++.h>

using namespace std;


int solve(string S,vector<int> cost)
{
    int n = S.length();

    int sum = 0;

    for(auto x : cost) sum += x;
    
    for(int i = 0;i<n;i++)
    {
        int temp = cost[i];

        while(i+1<n && S[i] == S[i+1])
        {
            temp = max(temp,cost[i+1]);
            i++;
        }
        sum -= temp;
    }

    return sum;
}