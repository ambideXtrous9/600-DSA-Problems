#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, vector<int>> mp;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]].push_back(i);
    }
    // Push char index in array
    // Then for each char take vec size and if even mark mid and mid-1 as -1 and for odd size mark mid as -1 and push the temp array to mp[ch]. Then push all index where ele is not -1 to arr and then sort and in string push all the char  from string to res string.

    for (auto x : mp)
    {
        vector<int> temp = x.second;
        char ch = x.first;

        int n = temp.size();

        if (n % 2 == 0)
        {
            int mid = n / 2;
            temp[mid] = -1;
            temp[mid - 1] = -1;
        }
        else
        {
            temp[n / 2] = -1;
        }
        mp[ch] = temp;
    }

    vector<int> in;

    for (auto x : mp)
    {
        for (int i = 0; i < x.second.size(); i++)
        {
            if (x.second[i] != -1)
                in.push_back(x.second[i]);
        }
    }

    sort(in.begin(), in.end());

    string res;
    for (int i = 0; i < in.size(); i++)
    {
        res.push_back(s[in[i]]);
    }
    cout << res;
}