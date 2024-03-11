/*Explanation
The order in initial arrays doesn't matter,
my first intuition is to sort the array.

For each number A[i]:

1.  There are i smaller numbers,
    so there are 2 ^ i sequences in which A[i] is maximum.
    we should do res += A[i] * 2^i

2.  There are n - i - 1 bigger numbers,
    so there are 2 ^ (n - i - 1) sequences in which A[i] is minimum.
    we should do res -= A[i] * 2^(n - i - 1)

Done.

Q. why do we plus mod before return?
A In Cpp and Java, mod on negative number will still get a negative number.

*/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) 
{
    long long int res = 0;

    int n = nums.size();

    int mod = 1e9+7;

    sort(nums.begin(),nums.end());

    long long int c = 1;

    for(int i = 0;i<n;i++)
    {
        res = (res + c*(nums[i]-nums[n-i-1]))%mod;

        c = (c * 2) % mod;

    }

    return (res);
    
}