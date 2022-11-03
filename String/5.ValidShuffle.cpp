#include <bits/stdc++.h>

using namespace std;


bool ValidShuffle(string S1,string S2, string S)
{
    int n1  = S1.length();
    int n2  = S2.length();
    int m  = S.length();

    sort(S1.begin(),S1.end());
    sort(S2.begin(),S2.end());
    sort(S.begin(),S.end());

    int j=0,k=0;

    for (int i = 0; i < m; i++)
    {
        if(S[i]==S1[j] && j<n1) j++;
        else if(S[i]==S2[k] && k<n2) k++;
        else return false;
    }

    return (j==n1 && k==n2);
}