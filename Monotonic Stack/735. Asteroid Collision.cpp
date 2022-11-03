#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int> &A)
{
    int n = A.size();
    stack<int> S;

    for (int i = 0; i < n; i++)
    {
        if (S.empty() || A[i] > 0)
        {
            S.push(A[i]);
        }
        else
        {
            while (!S.empty() && S.top() > 0 && S.top() < abs(A[i]))
            {
                S.pop();
            }
            if (!S.empty() && S.top() == abs(A[i]))
            {
                S.pop();
            }
            else if (S.empty() || S.top() < 0)
            {
                S.push(A[i]);
            }
        }
    }

    int m = S.size();

    vector<int> ans(m);

    for (int i = m - 1; i >= 0; i--)
    {
        ans[i] = S.top();
        S.pop();
    }

    return ans;
}