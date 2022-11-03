#include <bits/stdc++.h>

using namespace std;

bool sumZero(vector<int> temp, int *starti, int *endj)
{
    int n = temp.size();
    unordered_map<int, int> M;
    int sum = 0;

    int max_length = 0;

    for (int i = 0; i < n; i++)
    {
        sum += temp[i];

        if (sum == 0)
        {
            if (max_length < i + 1)
            {
                *starti = 0;
                *endj = i;
                max_length = i + 1;
            }
        }

        if (M.find(sum) != M.end())
        {
            if (max_length < i - M[sum])
            {
                *endj = i;
                *starti = M[sum] + 1;

                max_length = i - M[sum];
            }
        }
        else
            M[sum] = i;
    }

    return max_length != 0;
}

// The main function that finds Largest rectangle
// sub-matrix in a[][] whose sum is 0.
vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
{
    int row = a.size();
    int col = a[0].size();
    // Variables to store the final output
    int fup = 0, fdown = 0, fleft = 0, fright = 0;
    int up = 0, down = 0;
    int maxl = INT_MIN;

    for(int i=0;i<row;i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(a[i][j]==0) a[i][j] = -1;
        }
        
    }

    vector<vector<int>> V;

    // Set the left column
    for (int left = 0; left < col; left++)
    {
        // Initialize all elements of temp as 0
        vector<int> temp(row, 0);

        // Set the right column for the left column
        // set by outer loop
        for (int right = left; right < col; right++)
        {
            // Calculate sum between current left
            // and right for every row 'i'
            for (int i = 0; i < row; i++)
            {
                temp[i] += a[i][right];
            }

            bool nozero = sumZero(temp, &up, &down);

            int area = (down - up + 1) * (right - left + 1);

            if (nozero && area > maxl)
            {
                fup = up;
                fdown = down;
                fleft = left;
                fright = right;
                maxl = area;
            }
        }
    }

    if (fup == 0 && fdown == 0 && fleft == 0 && fright == 0 && a[0][0] != 0)
    {
        // cout << "No zero-sum sub-matrix exists";
        return V;
    }

    for (int i = fup; i <= fdown; i++)
    {
        vector<int> temp;
        for (int j = fleft; j <= fright; j++)
        {
            temp.push_back(a[i][j]);
        }
        V.push_back(temp);
    }

    return V;
}
