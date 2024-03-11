#include <bits/stdc++.h>

using namespace std;

string prefix(string a, string b)
{
    string temp;
    int m = a.length();
    int n = b.length();

    int i = 0;
    int j = 0;

    while (i != m && j != n)
    {
        if (a[i] == b[j])
            temp.push_back(a[i]);
        else
            break;
        i++;
        j++;
    }

    return temp;
}

string longestCommonPrefix(vector<string> &strs)
{

    string pref = "";
    if (strs.empty())
        return pref;
    pref = strs[0];
    for (int i = 1; i < strs.size(); i++)
        pref = prefix(pref, strs[i]);

    return pref;
}

string longestCommonPrefix(vector<string> &str)
{
    int n = str.size();
    if (n == 0)
        return "";
    string ans = "";
    sort(begin(str), end(str));
    string a = str[0];
    string b = str[n - 1];
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            ans = ans + a[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}