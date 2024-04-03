#include <bits/stdc++.h>

using namespace std;

int *findTwoElement(int *arr, int n)
{
    map<int, int> mp;

    int *p = new int[2];

    for (int i = 1; i <= n; i++)
    {
        mp[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    
    for (auto i : mp)
    {
        if (i.second > 1)
            p[0] = i.first;
        if (i.second == 0)
            p[1] = i.first;
    }
    
    return p;
}

void twoOddAppearing(int xo, int array[], int n)
{
    int firstSetBitXor = xo & ~(xo-1);

    int result[2];

    for (int i = 0; i < n; i++)
    {
        if ((array[i] & firstSetBitXor) != 0)
        {
            result[0] ^= array[i];
        }
        else
            result[1] ^= array[i];

        if (((i + 1) & firstSetBitXor) != 0)
        {
            result[0] ^= (i + 1);
        }
        else
            result[1] ^= (i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (result[1] == array[i])
        {
            int temp = result[0];
            result[0] = result[1];
            result[1] = temp;
            break;
        }
    }
}

void findTwoElement2(int arr[], int n)
{
    int xo = 0;
    for (int i = 0; i < n; i++)
    {
        xo ^= arr[i];
        xo ^= i + 1;
    }
    twoOddAppearing(xo,arr,n);
}