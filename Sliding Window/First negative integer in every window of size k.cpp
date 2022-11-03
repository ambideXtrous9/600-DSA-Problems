#include <bits/stdc++.h>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int n, long long int k)
{
    vector<long long> V;

    int i = 0;
    int j = 0;

    queue<int> Q;

    while (j < n)
    {
        if (A[j] < 0)
            Q.push(A[j]);

        if (j - i + 1 < k)
        {
            j++;
            continue;
        }
        else // == k
        {
            if (!Q.size())
                V.push_back(0);

            else
            {
                int val = Q.front();
                V.push_back(val);
                if (val == A[i])
                    Q.pop();
            }
            i++;
            j++;
        }
    }

    return V;
}