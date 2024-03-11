#include <bits/stdc++.h>

using namespace std;

string solve(int n, int k)
{

    vector<int> V;

    int fact = 1;

    for (int i = 1; i < n; i++)
    {
        V.push_back(i);
        fact *= i; // calculate the factorial(n-1)
    }

    V.push_back(n); // get the numbers to arr 1 to n

    string S = "";

    // k = k-1  for 1-based indexing

    while (1)
    {
        S += to_string(V[k / fact]);     // add number from the index to string
        V.erase(V.begin() + (k / fact)); // erase that number from that pos in arr

        if (V.size() == 0)
            break;

        k = k % fact;

        fact = fact / V.size();
    }

    return S;
}