#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int solve(string s)
{

    int n = s.size();

    stack<int> S;

    for (int i = n - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            int sum = 0;
            vector<int> V;
            bool isop = false;
            while (s[i] != ' ')
            {
                if (s[i] == '-')
                {
                    isop = true;
                }
                else
                {
                    V.push_back(s[i] - '0');
                }
                i--;
            }

            for (int k = V.size() - 1; k >= 0; k--)
            {
                sum = sum * 10 + V[k];
            }
            if (isop)
                sum = sum * (-1);
            S.push(sum);
            continue;
        }

        else if (isOperator(s[i]))
        {
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();

            int c = 0;

            if (s[i] == '+')
            {
                c = a + b;
            }
            if (s[i] == '-')
            {
                c = a - b;
            }
            if (s[i] == '*')
            {
                c = a * b;
            }
            if (s[i] == '/')
            {
                c = a / b;
            }

            S.push(c);
        }
    }

    return S.top();
}
