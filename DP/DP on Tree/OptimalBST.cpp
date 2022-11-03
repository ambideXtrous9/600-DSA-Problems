#include <bits/stdc++.h>

using namespace std;


int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}

int optCost(int freq[], int i, int j)
{
   if (j < i)      // no elements in this subarray
     return 0;
   if (j == i)     // one element in this subarray
     return freq[i];
   int fsum = sum(freq, i, j);
   int min = INT_MAX;
 
   for (int r = i; r <= j; ++r)
   {
       int cost = optCost(freq, i, r-1) + optCost(freq, r+1, j);
       if (cost < min)
          min = cost;
   }
   return min + fsum;
}
 

int optimalSearchTree(int keys[], int freq[], int n)
{
     return optCost(freq, 0, n-1);
}
 
int optimalSearchTree(int keys[], int freq[], int n)
{
    int cost[n][n];
 
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
 
    // Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
    for (int L=2; L<=n; L++)
    {
        // i is row number in cost[][]
        for (int i=0; i<=n-L+1; i++)
        {
            // Get column number j from row number i and
            // chain length L
            int j = i+L-1;
            cost[i][j] = INT_MAX;
 
            // Try making all keys in interval keys[i..j] as root
            for (int r=i; r<=j; r++)
            {
               // c = cost when keys[r] becomes root of this subtree
               int c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + sum(freq, i, j);
               if (c < cost[i][j])
                  cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}