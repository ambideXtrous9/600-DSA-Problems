#include <bits/stdc++.h>

using namespace std;

long long maxProduct(vector<int> A, int n)
{

    long long minVal = INT_MAX;
    long long maxVal = INT_MIN;

    long long M = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // when A[i] is -ve then multuply it with maxval yields minval and multuply with minval yields maxval
        //  so we need to swap it
        if (A[i] < 0)
        {
            long long temp = minVal;
            minVal = maxVal;
            maxVal = temp;
        }

        long long k = A[i];

        minVal = min(k, minVal * A[i]);
        maxVal = max(k, maxVal * A[i]);

        M = max(M, maxVal);
    }
    return M;
}