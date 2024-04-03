#include <bits/stdc++.h>

using namespace std;


int solution(const string &S)
{
    int ans = 0;
    vector<int> V;

    for(int i = 0;i<S.length();i++) 
    {
        if(S[i]=='R') V.push_back(i); 
    }

    int n = V.size();

    int s = 0;
    int e = n-1;

    while(s<e)
    {
        ans += (V[e] - V[s] - e + s);
        s++;
        e--;
    }

    if(ans>1e9) return -1;

    return ans;
}


int solution(const string &s)
{
    int red_count = 0;
    // count number of Rs in the string
    for (char c : s)
    {
        if (c == 'R')
            ++red_count;
    }
    
    // Init indexes to the ends of the string and the result
    int left = 0, right = s.size() - 1, result = 0;
    
    // moving from the ends to the middle
    while (left < right)
    {
        // if we meet pair of Rs on the ends
        if (s[left] == 'R' && s[right] == 'R')
        {
            // add to the result number of Ws between of these Rs
            red_count -= 2;
            result += right - left - 1 - red_count;
            // and shrink the processing window
            ++left;
            --right;
        }
        // pass all Ws we meet
        else if (s[left] != 'R')
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    return result;
}