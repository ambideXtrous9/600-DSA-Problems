// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
// User function template for C++

// Function to count subarrays with sum equal to 0.
ll findSubarray(vector<ll> arr, int n)
{
    // code here
    ll res = 0;
    unordered_map<ll, ll> m;
    
    ll presum = 0;
    
    for (int i = 0; i < n; i++)
    {
        m[presum]++;
        presum += arr[i];
        res += m[presum];
    }
    return res;
}
