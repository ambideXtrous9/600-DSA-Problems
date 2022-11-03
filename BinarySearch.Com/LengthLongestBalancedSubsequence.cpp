#include <bits/stdc++.h>

using namespace std;

int solve(string s)
{

    stack<char> S;

    int ans = 0;

    for (auto c : s)
    {
        if (c == '(')
        {
            S.push(c);
            continue;
        }
        else
        {
            if (S.empty())
            {
                continue;
            }
            else
            {
                ans++;
                S.pop();
            }
        }
    }

    return ans * 2;
}

int solve(string s) 
{

    int n = s.length();
    int open = 0;
 
    int close = 0;
 
    for (int i = 0; i < n; i++) 
    {
        if (s[i] == '(') 
        {
            open++;
        }
        else  // close )
        {
            if (open == 0) 
            {
                close++;
            }
            else 
            {
                open--;
            }
        }
    }
    return (n - (open + close));
    
}