#include <bits/stdc++.h>

using namespace std;

void permutation(string S, int i, set<string> &SE)
{
    if (i == S.length() - 1)
    {
        SE.insert(S);
        return;
    }

    for (int j = i; j < S.length(); j++)
    {
        swap(S[i], S[j]);
        permutation(S, i + 1, SE);
        swap(S[i], S[j]);
    }
}
vector<string> find_permutation(string S)
{
    set<string> SE;

    permutation(S, 0, SE);

    vector<string> V(SE.begin(), SE.end());

    return V;
}