#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) 
{
    
    pair<long long, long long> pp;
    long int mn = INT_MAX;
    long int mx = INT_MIN;
    
    for(long int i = 0;i<n;i++)
    {
        if(mn>a[i]) mn = a[i];
        if(mx<a[i]) mx = a[i];
    }
    
    pp.first = mn;
    pp.second = mx;
    
    return pp;
}