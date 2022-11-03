#include <bits/stdc++.h>

using namespace std;

vector<int> factorial(int N)
{
    // code here
    vector<int> res;
    res.push_back(1);
    for (int j = 2; j <= N; j++)
    {
        int carr = 0;
        for (int i = 0; i < res.size(); i++)
        {
            int val = res[i] * j + carr;
            res[i] = val % 10;
            carr = val / 10;
        }
        while (carr != 0)
        {
            res.push_back(carr % 10);
            carr /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}