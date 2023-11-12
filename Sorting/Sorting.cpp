#include<bits/stdc++.h>

using namespace std;

/*
Bubble Sort

1. at every step largest element will end up at the end of the array,
2. and i will reduce from the end ==> (n-1) to 0
3. j will iterate from start to < i for every i in the inner loop.
4. and if arr[j] > arr[j+1] ==> then swap 

*/

void BubbleSort(vector<int> arr)
{
    int n = arr.size();

    for(int i = n-1;i>=0;i--)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*
we can reduce the TC to O(n) by adding a flag var, 
if the array is already sorted
*/

void BubbleSortMod(vector<int> arr)
{
    int n = arr.size();

    for(int i = n-1;i>=0;i--)
    {
        bool flag = true;
        for(int j = 0;j<i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = false; 
            }
        }

        if(flag) break;
    }
}

// ------------------------------------------------------------------------ //

/*
Selection Sort : 

i current pos to be updated, and j will start from i+1 to search the number
to be placed at i in every iteration.

as j starts with (i+1) , i will reach till < (n-1) and j < n

1. for every position starts from 0, find the smallest for that pos in every itr and swap
2. i -> left part = sorted, right part = unsorted
3. i starts from 0 and goes till < (n-1)
4. j starts from (i+1) and goes till < n
5. and swap :   
                min = i;

                for(j = i+1 to n)
                    if(arr[min] > arr[j]) min = j;
                swap(arr[i],arr[min]);
*/

void SelectionSort(vector<int> arr)
{
    int n = arr.size();

    for(int i = 0;i<n-1;i++)
    {
        int min = i;

        for(int j = i+1;j<n;j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

//-----------------------------------------------------------------//

/*
Insertion Sort :

1. Select an element in each iteration from the unsorted array(using a loop).

2. Place it in its corresponding position in the sorted part and shift the remaining elements accordingly (using an inner loop and swapping).

3. The “inner while loop” basically shifts the elements using swapping.

-------------------------------------------------------------

1. at each iteration, left part of i will be sorted and right part will be unsorted
2. so at every iter, j will traverse from i to 0 and swap if arr[j-1] > arr[j]

i => 0 to < n
j => i to 0(at max) : while loop (j > 0 and arr[j-1] > arr[j]) swap(arr[j-1],arr[j])

*/

void InsertionSort(vector<int> arr)
{
    int n = arr.size();

    for(int i = 0;i<n;i++)
    {
        int j = i;
        while(j > 0 && arr[j-1] > arr[j])
        {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

//--------------------------------------------------------//

/*
Merge Sort:

1. split the array at middle recursively, then keep on merging splitted array in sorted order
2. mid = (low + high) / 2;
3. recursion termination condition -> if (low >= high) return

*/

void Merge(vector<int> arr, int low, int mid ,int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high)
    {
        if(arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = left;i<=right;i++)
    {
        arr[i] = temp[i-left];
    }
}
void MergeSort(vector<int> arr, int low, int high)
{
    if(low >= high) return;

    int mid = (high - low)/2 + low;

    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
    
}

/*--------------------------------------------------------------------*/

void Merge(int arr[], int low, int mid ,int high)
{
    int temp[high-low+1];
    int left = low;
    int right = mid+1;

    int i = 0;

    while(left <= mid && right <= high)
    {
        if(arr[left] < arr[right])
        {
            temp[i] = (arr[left]);
            left++;
            
        }
        else
        {
            temp[i] = (arr[right]);
            right++;
            
        }

        i++;
    }

    while(left <= mid)
    {
        temp[i] = (arr[left]);
        left++;
        i++;
    }
    while(right <= high)
    {
        temp[i] = (arr[right]);
        right++;
        i++;
    }

    for(int j = low;j<=high;j++)
    {
        arr[j] = temp[j-low];
    }
}



void mergeSort(int arr[], int l, int r) 
{
    if(l>=r) return;

    int mid = (r-l)/2 + l;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    Merge(arr, l, mid, r);

}

//-----------------------------------------------------------------------//

/*
Quick Sort

https://yongdanielliang.github.io/animation/web/QuickSortNew.html


*/

int Partition(vector<int> arr,int low,int high)
{
    int pivot = arr[low];
    int left = low;
    int right = high;
    
    while (left < right)
    {
        while (arr[left] <= pivot && left <= high-1)
        {
            left++;
        }

        while (arr[right] < pivot && right >= low-1)
        {
            right--;
        }

        if(left < right)
        {
            swap(arr[left],arr[right]);
        }
    }

    // put the pivot at right pos. left[] < pivot and right[] > pivot
    swap(arr[low],arr[right]); 
    return right;
}

void QuickSort(vector<int> arr,int low,int high)
{
    if(low>=high) return;

    int pivot = Partition(arr,low,high);

    QuickSort(arr,low,pivot-1);
    QuickSort(arr,pivot+1,high);
}
























