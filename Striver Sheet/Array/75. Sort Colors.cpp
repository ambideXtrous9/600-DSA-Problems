#include <bits/stdc++.h>

using namespace std;


/*

swap in A[mid] == 0 mid++, low++;
        A[mid] == 2 high--;
        A[mid] == 1 mid++;
        
low -> takes care of where 0s sholud be placed
high -> where 2s should be placed

*/

void sort012(int a[], int n)
{
    int l = 0;
    int m = 0;
    int h = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (a[m] == 0)
        {
            swap(a[m], a[l]);
            l++;
            m++;
        }
        else if (a[m] == 1)
        {
            m++;
        }
        else if (a[m] == 2)
        {
            swap(a[m], a[h]);
            h--;
        }
    }
}