#include <bits/stdc++.h>

using namespace std;

class ATM
{
public:
    vector<long long> notes;
    vector<long long> types;
    int n = 5;

    ATM()
    {
        notes = vector<long long>(n, 0);
        types = {20, 50, 100, 200, 500};
    }

    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < n; i++)
            notes[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount)
    {
        vector<int> arr(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (notes[i] > 0)
            {
                arr[i] = min(notes[i], amount / types[i]);
                amount -= arr[i] * types[i];
            }
        }

        if (amount > 0)
            return {-1};

        for (int i = 0; i < n; i++)
            notes[i] -= arr[i];

        return arr;
    }
};