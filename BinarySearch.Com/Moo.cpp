#include <bits/stdc++.h>

using namespace std;

string solve(string cows)
{
    queue<pair<char, int>> Q;
    int n = cows.size();

    for (int i = 0; i < n; i++)
    {
        if (cows[i] == 'L')
        {
            Q.push({'L', i});
        }
        else if (cows[i] == 'R')
        {
            Q.push({'R', i});
        }
    }

    while (!Q.empty())
    {
        int t = Q.size();

        vector<pair<char, int>> V;

        for (int i = 0; i < t; i++) // line by line BFS
        {
            int u = Q.front().second;
            char c = Q.front().first;
            Q.pop();

            if (c == 'L')
            {
                if (u - 1 < 0 or cows[u - 1] != '@')
                    continue; // left traversal not possible
                if (u - 2 >= 0 and cows[u - 2] == 'R')
                    continue;              // one of the edge acse for..L@R..
                V.push_back({'L', u - 1}); // place L in the left index to be updated
                Q.push({'L', u - 1});
            }
            else if (c == 'R')
            {
                if (u + 1 >= n or cows[u + 1] != '@')
                    continue; // right traversal not possible in current step
                if (u + 2 < n and cows[u + 2] == 'L')
                    continue;              // edge case ...R@L@..
                V.push_back({'R', u + 1}); // we traverse one step to right
                Q.push({'R', u + 1});
            }
        }
        for (auto x : V) // update the changes after every lavel
        {
            char c = x.first;
            int idx = x.second;

            cows[idx] = c;
        }
    }

    return cows;
}