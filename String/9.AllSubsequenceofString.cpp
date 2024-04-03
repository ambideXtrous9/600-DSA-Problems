#include <bits/stdc++.h>

using namespace std;

void printSubsequence(string S, string O, int i, int n)
{
    if (i == n)
    {
        cout << O << endl;
        return;
    }

    printSubsequence(S, O + S[i], i + 1, n); // take
    printSubsequence(S, O, i + 1, n);        // not take
}


void printSubsequence(string S, string O, int i)
{
    if (i == 0)
    {
        cout << O << endl;
        return;
    }

    printSubsequence(S, O + S[i-1], i - 1); // take
    printSubsequence(S, O, i - 1);        // not take
}


int main()
{

    string output = "";
    string input = "abcd";

    int n = input.length();

    printSubsequence(input, output, n);

    return 0;
}