#include <bits/stdc++.h>

using namespace std;

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
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> V;
    for (int i = 0; i < max(n, m); i++)
    {
        if (i < n)
        {
            V.push_back(a[i]);
        }
        if (i < m)
        {
            V.push_back(b[i]);
        }
    }
    buildHeap(V, m + n);
    return V;
}