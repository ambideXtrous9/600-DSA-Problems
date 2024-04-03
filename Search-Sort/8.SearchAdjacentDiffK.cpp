#include <bits/stdc++.h>

using namespace std;

/*
1. The idea is to start comparing from the leftmost element and 
2. find the difference between the current array element and x. 
3. Let this difference be ‘diff’. From the given property of the array, 
4. we always know that x must be at least ‘diff/k’ away, 
5. so instead of searching one by one, we jump ‘diff/k’.

*/

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;

        int step = abs(arr[i] - x) / k;

        i += max(1, step);
    }
    return -1;
    // Complete the function
}