
#include <bits/stdc++.h>
using namespace std;

int kthelement(int array1[], int array2[], int m, int n, int k)
{
    int p1 = 0, p2 = 0, counter = 0, answer = 0;

    while (p1 < m && p2 < n)
    {
        if (counter == k)
            break;
        else if (array1[p1] < array2[p2])
        {
            answer = array1[p1];
            ++p1;
        }
        else
        {
            answer = array2[p2];
            ++p2;
        }
        ++counter;
    }
    if (counter != k)
    {
        if (p1 != m - 1)
            answer = array1[k - counter];
        else
            answer = array2[k - counter];
    }
    return answer;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m)
    {
        return kthElement(arr2, arr1, m, n, k);
    }

    int low = max(0, k - m); // ensures we take at least one element from arr1
    int high = min(k, n); // ensures we can not take all the elements from arr2
    
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];
        
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
}