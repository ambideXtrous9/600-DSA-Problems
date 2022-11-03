#include <bits/stdc++.h>

using namespace std;

// NAIVE APPROACH => TC = O(n*m)

bool PatternCheck(string S1, string S2, int &l, int &r)
{
    int n = S1.length();
    int m = S2.length();

    int flag = 0;

    for (int i = 0; i + m <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (S1[i + j] == S2[j])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            l = i;
            r = i + m;
            flag = 0;
            return true;
        }
    }
    return false;
}

int main()
{
    string S1 = "ABABDABACDABABCABABAABBBCBCBAABDDCAB";
    string S2 = "ABABCABAB";
    int l = 0;
    int r = 0;
    cout << PatternCheck(S1, S2, l, r) << endl;

    cout << "Start = " << l << ", End = " << r << endl;
}




void LPS(string S, vector<int> &lps)
{
    int n = S.length();

    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i < n)
    {
        if (S[i] == S[len]) // match
        {
            lps[i++] = ++len;
        }
        else // mismatch
        {
            if (len != 0) //
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
                
        }
    }
}

void KMP(string S1, string S2)
{
    int n = S1.length();
    int m = S2.length();

    vector<int> lps(m,0);

    LPS(S2,lps);

    int i = 0;
    int j = 0; 
 
    while(i<n)
    {
        if(S1[i]==S2[j]) //match
        {
            i++;
            j++;
        }
        else //mismatch
        {
            if(j!=0)
            {
                j = lps[j-1];
            }
            else
                i++;
        }

        if(j==m)
        {
            cout << "Start = " << i-j << ", End = " << i << endl;

            // to find all occurences reset j again :
            // j = lps[j-1];
        }
    }
}

int main()
{
    string S1 = "ABABDABACDABABCABABAABBBCBCBAABDDCAB";
    string S2 = "ABABCABAB";
    KMP(S1, S2);
}