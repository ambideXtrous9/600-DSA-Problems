#include <bits/stdc++.h>

using namespace std;

int solve(string s)
{

    int n = s.length();
    stack<int> S;

    S.push(-1);

    int ans = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            S.push(i);
        }
        else
        {
            S.pop();

            if (!S.empty())
            {
                int len = i - S.top();
                ans = max(ans, len);
            }
            else
            {
                S.push(i);
            }
        }
    }
    return ans;
}

int solve(string s)
{
    int n = s.length();

    int open = 0;
    int close = 0; 

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else
        {
            close++;
        }

        if(close>open) open = close = 0;

        if(open == close) 
        {
            ans = max(ans,open+close);
        }

    }

    open = 0;
    close = 0; 

    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else
        {
            close++;
        }

        if(open>close) open = close = 0;

        if(open == close) 
        {
            ans = max(ans,open+close);
        }
    }

    return ans;
}