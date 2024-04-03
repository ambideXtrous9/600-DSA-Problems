#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
    // Base cases
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
    return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}

int countDer(int n)
{
    // Create an array to store
    // counts for subproblems
    vector<int> der(n + 1, 0);

    // Base cases
    der[1] = 0;
    der[2] = 1;

    // Fill der[0..n] in bottom up manner
    // using above recursive formula
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]);

    // Return result for n
    return der[n];
}

int countDer(int n)
{
    if (n == 1 or n == 2)
    {
        return n - 1;
    }

    int a = 0;
    int b = 1;

    for (int i = 3; i <= n; ++i)
    {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }

    return b;
}