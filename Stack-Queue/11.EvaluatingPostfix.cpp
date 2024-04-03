#include <bits/stdc++.h>

using namespace std;

int evaluatePostfix(string S)
{
    stack<int> st;

    for (auto c : S)
    {
        if (c >= '0' && c <= '9')
        {
            st.push(c - '0');
        }
        else
        {
            int op1;
            int op2;

            if (!st.empty())
            {
                op1 = st.top();
                st.pop();
            }
            if (!st.empty())
            {
                op2 = st.top();
                st.pop();
            }

            int res;

            if (c == '*')
                res = op2 * op1;
            else if (c == '/')
                res = op2 / op1;
            else if (c == '+')
                res = op2 + op1;
            else if (c == '-')
                res = op2 - op1;

            st.push(res);
        }
    }

    return st.top();
}