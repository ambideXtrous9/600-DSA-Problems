#include <bits/stdc++.h>

using namespace std;

int mod = 1e3 + 3;
int solve(string S, int i, int j, bool flag, unordered_map<string, int> &M)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (flag == true)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }

    int ans = 0;

    string temp = to_string(i) + "_" + to_string(j) + "_" + to_string(flag);

    if (M.find(temp) != M.end())
        return M[temp];

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lf = solve(S, i, k - 1, false, M);
        int lt = solve(S, i, k - 1, true, M);
        int rf = solve(S, k + 1, j, false, M);
        int rt = solve(S, k + 1, j, true, M);

        if (S[k] == '&')
        {
            if (flag == true)
                ans += lt * rt;
            else
                ans += lt * rf + lf * rt + lf * rf;
        }
        else if (S[k] == '|')
        {
            if (flag == true)
                ans += lt * rt + lt * rf + lf * rt;
            else
                ans += lf * rf;
        }
        else if (S[k] == '^')
        {
            if (flag == true)
                ans += lt * rf + lf * rt;
            else
                ans += lf * rf + lt * rt;
        }
    }

    return M[temp] = ans % mod;
}
int countWays(int N, string S)
{
    unordered_map<string, int> M;
    return solve(S, 0, N - 1, true, M);
}
