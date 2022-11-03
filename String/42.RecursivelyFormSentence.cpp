
#include <bits/stdc++.h>

using namespace std;

void printUtil(vector<vector<string>> arr, vector<string> &S, int count, int i, int n, vector<vector<string>> &W)
{
    if (count == n || i >= n)
    {
        W.push_back(S);
        return;
    }
    int m = arr[i].size();
    for (int j = 0; j < m; j++)
    {
        S.push_back(arr[i][j]);
        S.push_back(" ");
        printUtil(arr, S, count + 1, i + 1, n, W);
        S.pop_back(); // backtracking step (making space for next level words)
        S.pop_back();
    }
}

// Driver program to test above functions
int main()
{
    vector<vector<string>> V = {{"you", "we", "They"},
                                {"have", "are", "should"},
                                {"sleep", "eat", "drink"}};

    int n = V.size();
    int m = V[0].size();

    vector<vector<string>> W;

    for (int i = 0; i < m; i++)
    {
        vector<string> S;
        S.push_back(V[0][i]);
        S.push_back(" ");
        int count = 1;
        printUtil(V, S, count, 1, n, W);
    }

    for (int i = 0; i < W.size(); i++)
    {
        for (int j = 0; j < W[0].size(); j++)
        {
            cout << W[i][j];
        }
        cout << "\n";
    }

    return 0;
}