#include <bits/stdc++.h>

using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> umap;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (umap.find(k - arr[i]) != umap.end())
        {
            count += umap[k - arr[i]];
            //
        }
        umap[arr[i]]++;
    }
    return count;
    // code here
}

int printPairs(int arr[], int n, int sum)
{
    int count = 0; // Initialize result

    // Consider all possible pairs and check
    // their sums
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                cout << "(" << arr[i] << ", "
                     << arr[j] << ")" << endl;
}

void printPairsII(int arr[], int n, int sum)
{
    // Store counts of all elements in map m
    unordered_map<int, int> m;

    // Traverse through all elements
    for (int i = 0; i < n; i++)
    {

        // Search if a pair can be formed with
        // arr[i].
        int rem = sum - arr[i];
        if (m.find(rem) != m.end())
        {
            int count = m[rem];
            
            for (int j = 0; j < count; j++)
                cout << "(" << rem << ", "<< arr[i] << ")" << endl;
        }
        m[arr[i]]++;
    }
}