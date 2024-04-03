#include <bits/stdc++.h>

using namespace std;

vector<int> getCoordinate(int n, int s)
{
    int row = n - 1 - (s - 1) / n;
    int col = (s - 1) % n;
    if (n % 2 == row % 2)
        col = n - 1 - col;
    return {row,col};
}
int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vector<bool> seen(n * n + 1, false);
    seen[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int row, col, s = p.first, dist = p.second;
        if (s == n * n)
            return dist;
        for (int i = 1; s + i <= n * n && i <= 6; i++)
        {
            vector<int> coord = getCoordinate(n, s + i);
            int row = coord[0];
            int col = coord[1];
            int sfinal = board[row][col] == -1 ? s + i : board[row][col]; // check for snake or ladder
            if (seen[sfinal] == false)
            {
                seen[sfinal] = true;
                q.push({sfinal, dist + 1});
            }
        }
    }
    return -1;
}