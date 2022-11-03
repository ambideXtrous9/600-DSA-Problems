#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i) 
{
    int lar = i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l<n && arr[l]>arr[lar]) lar = l;
    if(r<n && arr[r]>arr[lar]) lar = r;
    
    if(lar!=i)
    {
        swap(arr[i],arr[lar]);
        heapify(arr,n,lar);
    }
    
}

// Main function to do heap sort
void buildHeap(int arr[], int n) 
{
    int stIdx = (n/2) - 1;
    for(int i=stIdx;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    
    for(int i = n-1;i>0;i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}