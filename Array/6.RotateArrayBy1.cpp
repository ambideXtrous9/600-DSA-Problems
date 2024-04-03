#include <bits/stdc++.h>

using namespace std;

void rotate(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[i], arr[i - 1]);
    }
}

void RightRotate(int a[], int n, int k)
{

    // If rotation is greater
    // than size of array
    k = k % n;

    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {

            // Printing rightmost
            // kth elements
            cout << a[n + i - k] << " ";
        }
        else
        {

            // Prints array after
            // 'k' elements
            cout << (a[i - k]) << " ";
        }
    }
    cout << "\n";
}

void LeftRotate(int a[], int n, int k)
{

    // If rotation is greater
    // than size of array
    k = k % n;

    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {

            // Printing rightmost
            // kth elements
            cout << a[n + i - k] << " ";
        }
        else
        {

            // Prints array after
            // 'k' elements
            cout << (a[i - k]) << " ";
        }
    }
    cout << "\n";
}

void leftRotate(int arr[], int r, int n)
{
    // base case: invalid input
    if (r < 0 || r >= n)
    {
        return;
    }

    // construct an auxiliary array of size `r` and
    // fill it with the first `r` elements of the input array
    int aux[r];
    for (int i = 0; i < r; i++)
    {
        aux[i] = arr[i];
    }

    // shift the remaining `n-r` elements of the input array at the beginning
    for (int i = r; i < n; i++)
    {
        arr[i - r] = arr[i];
    }

    // put the elements of the auxiliary array at their
    // correct positions in the input array
    for (int i = n - r; i < n; i++)
    {
        arr[i] = aux[i - (n - r)];
    }
}

void rightRotate(int A[], int k, int n)
{
    // base case: invalid input
    if (k < 0 || k >= n)
    {
        return;
    }

    // construct an auxiliary array of size `k` and
    // fill it with the last `k` elements of the input array
    int aux[k];
    for (int i = 0; i < k; i++)
    {
        aux[i] = A[n - k + i];
    }

    // shift the first `n-k` elements of the input array at the end
    for (int i = n - k - 1; i >= 0; i--)
    {
        A[i + k] = A[i];
    }

    // put the elements of the auxiliary array at their
    // correct positions in the input array
    for (int i = 0; i < k; i++)
    {
        A[i] = aux[i];
    }
}