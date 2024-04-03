#include <bits/stdc++.h>

using namespace std;

/*
Approach <Constant Size sliding window>

1. first calculate total number of element in array
which is less than k (that beacomes a window size)
2. then start window slide algo
3. if greater than k (arr[j] > k) element come in window we increase bad++
when we hit window size (j-i+1 == count) we check for min of bad
and slide the window by checking if ith element is is contibuting in bad tou make bad-- and do  i++
*/

int minSwap(int arr[], int n, int k)
{
    // Complet the function
    int count = 0; // number of element less than or equal k (window size)
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            count++;

    // koi element chota hai hi ni tou kese
    if (count == 0)
        return 0;
    
    int i = 0, j = 0;
    int bad = 0;
    int ans = INT_MAX;

    while (j < n)
    {
        if (arr[j] > k)
            bad++; // curr window me kitne greater k ele(jinko swap krna hoga)
        
        if (j - i + 1 < count)
            j++;
        
        else if (j - i + 1 == count)
        {
            ans = min(ans, bad);
            
            // slide windlow
            if (arr[i] > k)
                bad--;
            
            i++; 
            j++;
        }
    }
    return ans;
}