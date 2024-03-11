#include <bits/stdc++.h>

using namespace std;

int d = 26;   // Base value of alphabets
int p = 9999991; // Large prime number

void RabinKarp(string pat, string txt)
{
    int patHash = 0; // Hash value of pattern
    int txtHash = 0; // Hash value of text
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i < m; i++) // Generating Hash values for pattern and first window text
    {
        patHash = patHash * d;
        txtHash = txtHash * d;
        patHash = patHash + ((pat[i] - 'A' + 1) % p);
        txtHash = txtHash + ((txt[i] - 'A' + 1) % p);
    }
    for (int i = 0; i <= n - m; i++) // Loop of text size minus  window
    {
        if (patHash == txtHash)
        {
            cout << "Pattern found at index = " << i<<endl;
        }

        if (i <= n - m)
        {
            txtHash = txtHash - ((txt[i] - 'A' + 1) * (int)pow(d, m - 1))%p; // Subtracting first element from current hash of d^window-1
            txtHash = txtHash * d + (txt[i + m] - 'A' + 1)%p;           // multiplying obtained hash with d to left shift the number and then adding the next new element
        }
    }
}

int main()
{
    string S1 = "ABABDABACDABABCABAB";
    string S2 = "ABABC";

    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";

    RabinKarp(pat, txt);
}