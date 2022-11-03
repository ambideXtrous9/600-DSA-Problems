#include <bits/stdc++.h>

using namespace std;

/*
Time Complexity: O(n*log(log(n)))
Auxiliary Space: O(n)
*/

int N = 100000;

int sieveOfEratosthenes(int n, int k)
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

    int count = 0;
    int sum = 0;

    for (int i = 2; i <= N; i++)
    {
        if (count == n)
            break;

        if (primes[i] && i % 10 == k)
        {
            sum += i;

            cout << i << " ";

            count++;
        }
    }

    sum += 7;

    return sum;
}

int main()
{

    int n = 7;
    int k = 1;

    int val = sieveOfEratosthenes(n, k);

    cout << endl;
    cout << "Answer = " << val << endl;

    return 0;
}