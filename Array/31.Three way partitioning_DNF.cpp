#include <bits/stdc++.h>

using namespace std;


// DNF Algorithm

void threeWayPartition(vector<int> &array, int a, int b)
{
    int n = array.size();

    int low = 0;
    int mid = 0;
    int high = n-1;

    for (int i = 0; i < n; i++)
    {
        if (array[mid] < a)
        {
            swap(array[mid], array[low]);
            low++;
            mid++;
        }
        else if (array[mid] <= b && array[mid] >= a)
        {
            mid++;
        }
        else
        {
            swap(array[mid], array[high]);
            high--;
        }
    }
}

void threeWayPartition(vector<int> &array, int a, int b)
{
    int low = 0;

    int mid = 0;

    int high = (array.size() - 1);

    while (mid <= high)
    {
        if (array[mid] < a)
        {
            int temp = array[mid];
            array[mid] = array[low];
            array[low] = temp;

            low++;
            mid++;
        }
        else if (array[mid] <= b && array[mid] >= a)
        {
            mid++;
        }
        else
        {
            int temp = array[mid];
            array[mid] = array[high];
            array[high] = temp;

            high--;
        }
    }
}