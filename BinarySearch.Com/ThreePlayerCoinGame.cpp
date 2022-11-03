#include <bits/stdc++.h>

using namespace std;


// 1. sort the array.
// 2. pick 2 highest and 1 lowest
// 3. keep the 2nd highest for you 


int solve(vector<int>& piles) 
{
    int n = piles.size();
    sort(piles.begin(),piles.end());

    int i = 0;
    int j = n-2;
    int sum = 0;
    
    while(j>i)
    {
        sum += piles[j];
        j -= 2;
        i++;
    }

    return sum;
    
}