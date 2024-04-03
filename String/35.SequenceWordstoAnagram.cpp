#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &s)
{
    vector<vector<string>> vect;
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < s.size(); i++)
    {
        string word = s[i];
        sort(word.begin(), word.end());
        mp[word].push_back(s[i]);
    }
    
    for (auto i : mp)
        vect.push_back(i.second);
    
    return vect;
}