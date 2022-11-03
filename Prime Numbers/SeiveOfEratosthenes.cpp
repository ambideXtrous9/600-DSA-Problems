#include <bits/stdc++.h>

using namespace std;

/*
Time Complexity: O(n*log(log(n)))
Auxiliary Space: O(n)
*/

vector<int> sieveOfEratosthenes(int N)
{
    vector<bool> primes(N + 1, true);

    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                primes[j] = false;
            }
        }
    }

    vector<int> ans;

    for (int i = 2; i <= N; i++)
    {
        if (primes[i])
            ans.push_back(i);
    }

    return ans;
}