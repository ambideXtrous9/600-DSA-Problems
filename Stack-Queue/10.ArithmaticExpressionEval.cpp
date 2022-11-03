#include <bits/stdc++.h>

using namespace std;

int prece(char a)
{
    if (a == ')' || a == '(')
    {
        return 5;
    }
    if (a == '^')
    {
        return 4;
    }
    if (a == '*' || a == '/')
    {
        return 2;
    }

    if (a == '+' || a == '-')
    {
        return 1;
    }
}

string InfixToPostfix(string s)
{
    int n = s.length();
   
    stack<char> st;

    string result = "";

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && prece(s[i]) <= prece(st.top()))
            {
                if (c == '^' && st.top() == '^')
                    break;
                else
                {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }


    return result;
}

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