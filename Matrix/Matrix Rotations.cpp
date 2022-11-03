#include <bits/stdc++.h>

using namespace std;

/*
Approach:
1. We first transpose the given matrix,
2. hen reverse the content of individual rows to get the resultant 90 degree clockwise rotated matrix.
*/

void rotate90clockwise(int mat[5][5])
{
    int n = 5;
    // Transpose of matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);

    // Reverse individual rows
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {
            swap(mat[i][low], mat[i][high]);
            low++;
            high--;
        }
    }
}

// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int a[][5])
{
    int N = 5;

    // Traverse each cycle
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {

            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

/*
1. Reverse every individual  row
2. Perform Transpose
*/

// anti-clockwise direction
void rotateMatrix(int mat[][5])
{ // REVERSE every row

    int N = 5;
    for (int i = 0; i < N; i++)
        reverse(mat[i], mat[i] + N);

    // Performing Transpose
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
            swap(mat[i][j], mat[j][i]);
    }
}

void rotateMatrix(int mat[][5])
{
    int N = 5;
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++)
    {
        // Consider elements in group
        // of 4 in current square
        for (int y = x; y < N - x - 1; y++)
        {
            // Store current cell in
            // temp variable
            int temp = mat[x][y];

            // Move values from right to top
            mat[x][y] = mat[y][N - 1 - x];

            // Move values from bottom to right
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

            // Move values from left to bottom
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

            // Assign temp to left
            mat[N - 1 - y][x] = temp;
        }
    }
}