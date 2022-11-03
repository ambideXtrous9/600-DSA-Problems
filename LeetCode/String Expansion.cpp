#include <bits/stdc++.h>

using namespace std;

string solve(string s)
{

    stack<string> S;
    stack<int> N;

    string res = "";

    int n = 0;

    for (auto c : s)
    {
        if (isdigit(c))
        {
            n = n * 10 + (c - '0');
        }

        else if (isalpha(c))
        {
            res += c;
        }

        else if (c == '(')
        {
            N.push(n);
            S.push(res);

            res = "";
            n = 0;
        }
        else
        {
            string cur = res;

            if (N.top() == 0)
                res = "";

            for (int i = 1; i < N.top(); i++)
            {
                res += cur;
            }

            res = S.top() + res;

            S.pop();
            N.pop();
        }
    }
    
    return res;
}