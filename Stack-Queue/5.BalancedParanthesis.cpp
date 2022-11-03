#include <bits/stdc++.h>

using namespace std;

bool ispar(string x)
{
    stack<char> S;

    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[')
        {
            S.push(x[i]);
        }
        else
        {
            if (x[i] == ')' && (S.empty() || S.top() != '('))
                return false;
            else if (x[i] == '}' && (S.empty() || S.top() != '{'))
                return false;
            else if (x[i] == ']' && (S.empty() || S.top() != '['))
                return false;

            S.pop();
        }
    }

    return S.empty();
}