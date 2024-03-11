#include <bits/stdc++.h>

using namespace std;

vector<int> NSL(vector<int> arr)
{
    int n = arr.size();
    stack<pair<int, int>> S;

    vector<int> V(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && S.top().first >= arr[i])
        {
            S.pop();
        }
        if (!S.empty())
            V[i] = S.top().second;
        else
            V[i] = -1;

        S.push({arr[i], i});
    }

    return V;
}

vector<int> NSR(vector<int> arr)
{
    int n = arr.size();
    stack<pair<int, int>> S;

    vector<int> V(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top().first >= arr[i])
        {
            S.pop();
        }
        if (!S.empty())
            V[i] = S.top().second;

        else
            V[i] = n;

        S.push({arr[i], i});
    }

    return V;
}

int MAH(vector<int> &arr)
{
    vector<int> V1 = NSR(arr);
    vector<int> V2 = NSL(arr);

    int maxi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = (V1[i] - V2[i] - 1) * arr[i];
        maxi = max(maxi, temp);
    }
    return maxi;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> V;

    for (int i = 0; i < m; i++)
    {
        V.push_back(matrix[0][i] - '0');
    }

    int maxi = MAH(V);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                V[j] = 0;
            else
                V[j] += matrix[i][j] - '0';
        }
        maxi = max(maxi, MAH(V));
    }

    return maxi;
}