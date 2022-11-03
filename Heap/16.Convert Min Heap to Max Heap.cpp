#include <bits/stdc++.h>

using namespace std;

/*
The idea is, simply build Max Heap without caring about the input.
Start from the bottom-most and rightmost internal node of Min-Heap
and heapify all internal modes in the bottom-up way to build the Max heap.
*/

void max_heapify(vector<int> &V, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int largest = i;

    int n = V.size();

    if (l < n && V[l] > V[largest])
    {
        largest = l;
    }
    if (r < n && V[largest] < V[r])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(V[i], V[largest]);
        max_heapify(V, largest);
    }
}
void buildHeap(vector<int> &V, int n)
{
    int stIdx = (n / 2) - 1;
    for (int i = stIdx; i >= 0; i--)
    {
        max_heapify(V, i);
    }
}