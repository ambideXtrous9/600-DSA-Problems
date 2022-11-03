#include <bits/stdc++.h>

using namespace std;

long long  pow(long long  x, long long  y, long long m)
{
    x %= m;
    
    if (x == 0)
        return 0;
    
    long long  res = 1;
    
    while (y > 0)
    {
        if (y & 1)
            res = ((res % m) * (x % m)) % m;

        y >>= 1;
        
        x = ((x % m) * (x % m)) % m;
    }
    
    return res;
}

long long solve(int s, int n, int m)
{
    int mod = 1e9+7;
    long long  res = pow(s, n, 10);
    res = pow(res, m, mod);
    return res;
}

int main()
{
    cout<<solve(2,2,1e9+7);
}