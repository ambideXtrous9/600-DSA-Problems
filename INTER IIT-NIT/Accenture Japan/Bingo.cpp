#include <bits/stdc++.h>

using namespace std;

bool bingo(vector<vector<char>> &M, int n, int m)
{

    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (M[i][i] == 'X')
            flag = false;

        if (!flag)
            break;
    }

    if (flag)
        return true;

    flag = true;

    for (int i = 0; i < n; i++)
    {
        if (M[i][n - 1 - i] == 'X')
            flag = false;

        if (!flag)
            break;
    }

    if (flag)
        return true;

    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 'X')
                flag = false;

            if (!flag)
                break;
        }

        if (flag)
            return true;
    }

    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = 0; j < m; j++)
        {
            if (M[j][i] == 'X')
                flag = false;

            if (!flag)
                break;
        }

        if (flag)
            return true;
    }

    return false;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<char>> M(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }

    bool x = bingo(M, n, m);

    cout << x << endl;

    return 0;
}