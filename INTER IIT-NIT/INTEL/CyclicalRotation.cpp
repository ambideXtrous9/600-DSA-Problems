#include <bits/stdc++.h>

using namespace std;

void putInTheGrid(vector<vector<int>> &grid, int x, int y, int m, int n, vector<int> &arr)
{
    int len = 2 * (m + n - 2);
    int count = 0;
    
    int startx = x;
    int starty = y;

    for (; x < startx + m; x++)
    {
        grid[x][y] = arr[count++];
    }
    
    x--;
    y++;
    
    for (; y < starty + n; y++)
    {
        grid[x][y] = arr[count++];
    }
    
    y--;
    x--;
    
    for (; x >= startx; x--)
    {
        grid[x][y] = arr[count++];
    }
    
    x++;
    y--;

    for (; y > starty; y--)
    {
        grid[x][y] = arr[count++];
    }
}
vector<int> rotate(vector<int> &arr, int k)
{
    int n = arr.size();
    if (k < 0)
    {
        return arr;
    }

    std::rotate(arr.begin(), arr.begin() + n - k, arr.end());

    return arr;
}

vector<int> createArray(vector<vector<int>> &grid, int x, int y, int m, int n)
{
    int len = 2 * (m + n - 2);
    
    vector<int> arr(len);
    
    int count = 0;
    
    int startx = x;
    int starty = y;
    
    for (; x < startx + m; x++)
    {
        arr[count++] = grid[x][y];
    }
    x--;
    y++;
    for (; y < starty + n; y++)
    {
        arr[count++] = grid[x][y];
    }
    y--;
    x--;
    for (; x >= startx; x--)
    {
        arr[count++] = grid[x][y];
    }
    x++;
    y--;
    for (; y > starty; y--)
    {
        arr[count++] = grid[x][y];
    }
    return arr;
}

vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();

    int x = 0;
    int y = 0;

    while (m > 0 && n > 0)
    {
        vector<int> array = createArray(grid, x, y, m, n);

        int temp = k % (2 * (m + n - 2));

        vector<int> rotateArray = rotate(array, temp);

        putInTheGrid(grid, x, y, m, n, rotateArray);
        
        m -= 2;
        n -= 2;
        x += 1;
        y += 1;
    }

    return grid;
}
