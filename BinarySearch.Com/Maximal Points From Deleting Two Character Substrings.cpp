#include <bits/stdc++.h>

using namespace std;

string process(string &str, char firstChar, char secondChar, int score, int &count)
{
    // works like a stack as we need processed string as well we use string instead of stack.
    // we can use stack also
    string result;  

    for (auto ch : str)
    {
        if (result == "" or ch != secondChar) // store 1st char always
        {
            result += ch;
            continue;
        }

        if (ch == secondChar && result.back() == firstChar) // removing one pair and add points
        {
            count += score;
            result.pop_back();
        }
        else // otherwise store the 2nd char
        {
            result += ch;
        }
    }

    return result;
}

int solve(string s, int zeroone, int onezero)
{
    int count = 0;

    // greedy approach to get max score.
    if (zeroone >= onezero) 
    {
        auto temp = process(s, '0', '1', zeroone, count);
        process(temp, '1', '0', onezero, count);
    }
    else
    {
        auto temp = process(s, '1', '0', onezero, count);
        process(temp, '0', '1', zeroone, count);
    }

    return count;
}