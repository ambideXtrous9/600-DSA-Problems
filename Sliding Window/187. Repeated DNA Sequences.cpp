#include <bits/stdc++.h>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{

    int n = s.length();

    int i = 0;
    int j = 0;

    unordered_map<string, int> S;
    vector<string> V;

    string temp = "";

    while (j < n)
    {
        temp += s[j];

        if (temp.length() < 10)
        {
            j++;
        }
        else if (temp.length() == 10)
        {

            S[temp]++;
            j++;
        }
        else
        {
            temp.erase(0, 1);

            if (temp.length() == 10)
            {

                S[temp]++;
            }
            j++;
        }
    }

    for (auto x : S)
        if (x.second > 1)
            V.push_back(x.first);

    return V;
}