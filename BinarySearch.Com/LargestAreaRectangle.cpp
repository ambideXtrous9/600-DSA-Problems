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

int MAH(vector<int> arr)
{
    vector<int> V1 = NSR(arr);
    vector<int> V2 = NSL(arr);

    int maxi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = (V1[i] - V2[i] - 1) * arr[i];
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int solve(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> V;

    for (int i = 0; i < m; i++)
    {
        V.push_back(matrix[0][i]);
    }

    int maxi = MAH(V);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
                V[j] = 0;
            else
                V[j] += matrix[i][j];
        }
        maxi = max(maxi, MAH(V));
    }

    return maxi;
}

int solve(vector<vector<int>> &matrix)
{
    if (!matrix.size() || !matrix[0].size())
        return 0;
    int i, j, m = matrix.size(), n = matrix[0].size(), ret = 0;
    vector<int> height(n + 1, 0);
    for (i = 0; i < m; i++)
    {
        vector<int> st;
        for (j = 0; j <= n; j++)
        {
            if (j < n)
                height[j] = (matrix[i][j] ? height[j] + 1 : 0);
            while (st.size() && height[st.back()] >= height[j])
            {
                int h = height[st.back()];
                st.pop_back();
                int w = (st.size() ? j - st.back() - 1 : j);
                ret = max(ret, w * h);
            }
            st.push_back(j);
        }
    }
    return ret;
}
