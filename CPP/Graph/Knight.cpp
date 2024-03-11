#include <bits/stdc++.h>

using namespace std;

void minStepDFS(int i, int j, int c, int d, int N, int cnt, int &ans, vector<vector<bool>> &vis)
{
    if (i < 0 || i >= N || j < 0 || j >= N || vis[i][j] || cnt > ans)
        return;

    if (i == c && j == d)
    {
        ans = min(ans, cnt);
        return;
    }

    vis[i][j] = true;

    minStepDFS(i + 2, j + 1, c, d, N, cnt + 1, ans, vis);
    minStepDFS(i + 2, j - 1, c, d, N, cnt + 1, ans, vis);
    minStepDFS(i - 2, j + 1, c, d, N, cnt + 1, ans, vis);
    minStepDFS(i - 2, j - 1, c, d, N, cnt + 1, ans, vis);
    minStepDFS(i + 1, j + 2, c, d, N, cnt + 1, ans, vis);
    minStepDFS(i + 1, j - 2, c, d, N, cnt + 1, ans, vis);
    minStepDFS(i - 1, j + 2, c, d, N, cnt + 1, ans, vis);
    minStepDFS(i - 1, j - 2, c, d, N, cnt + 1, ans, vis);

    vis[i][j] = false; // backtracking
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<bool>> vis(N, vector<bool>(N, false));

    int ans = INT_MAX;
    int cnt = 0;
    minStepDFS(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], N, cnt, ans, vis);

    return ans;
}

// Minimum Step by Knight Solution
typedef pair<int, pair<int, int>> PPI;
bool isValid(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, false));

    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    queue<PPI> Q;

    Q.push({0, {KnightPos[0], KnightPos[1]}});
   
    vis[KnightPos[0]][KnightPos[1]] = true;

    while (!Q.empty())
    {
        int x = Q.front().second.first;
        int y = Q.front().second.second;

        int count = Q.front().first;
        Q.pop();

        if (x == TargetPos[0] && y == TargetPos[1])
        {
            return count;
        }

        for (int i = 0; i < 8; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (isValid(tx, ty, N) && !vis[tx][ty])
            {
                vis[tx][ty] = true;
                Q.push({count + 1, {tx, ty}});
            }
        }
    }
    // Code here
}
// { Driver Code Starts.
int main()
{
    vector<int> KnightPos(2);
    vector<int> TargetPos(2);
    int N;
    cin >> N;
    cin >> KnightPos[0] >> KnightPos[1];
    cin >> TargetPos[0] >> TargetPos[1];
    int ans = minStepToReachTarget(KnightPos, TargetPos, N);
    cout << ans << "\n";
    return 0;
} // } Driver Code Ends