#include <bits/stdc++.h>

using namespace std;

/*

Let f(i, j) be minimum merging operations to make subarray arr[i..j] a palindrome. If i == j answer is 0. We start i from 0 and j from n-1.

1. If arr[i] == arr[j], then there is no need to do any merging operations at index i or index j. 
Our answer in this case will be f(i+1, j-1).
Else, we need to do merging operations. Following cases arise.

2. If arr[i] > arr[j], then we should do merging operation at index j. 
We merge index j-1 and j, and update arr[j-1] = arr[j-1] + arr[j]. 
Our answer in this case will be 1 + f(i, j-1).

3. For the case when arr[i] < arr[j], update arr[i+1] = arr[i+1] + arr[i]. 
Our answer in this case will be 1 + f(i+1, j).
Our answer will be f(0, n-1), where n is the size of array arr[].

*/

int findMinOps(int arr[], int n)
{
    int ans = 0; // Initialize result

    // Start from two corners
    for (int i = 0, j = n - 1; i <= j;)
    {
        // If corner elements are same,
        // problem reduces arr[i+1..j-1]
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }

        // If left element is greater, then
        // we merge right two elements
        else if (arr[i] > arr[j])
        {
            // need to merge from tail.
            j--;
            arr[j] += arr[j + 1];
            ans++;
        }

        // Else we merge left two elements
        else
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
    }

    return ans;
}