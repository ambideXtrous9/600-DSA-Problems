#include <bits/stdc++.h>

using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    map<int, int> m1;
    map<int, int> m2;
    map<int, int> m3;

    vector<int> v;
    
    for (int i = 0; i < n1; i++)
    {
        m1[A[i]]++;
    }
    
    for (int i = 0; i < n2; i++)
    {
        if (m1[B[i]])
        {
            m2[B[i]]++;
        }
    }
    
    for (int i = 0; i < n3; i++)
    {
        if (m2[C[i]])
        {
            m3[C[i]]++;
        }
    }

    map<int, int>::iterator itr;
    
    for (itr = m3.begin(); itr != m3.end(); itr++)
    {
        v.push_back(itr->first);
    }
    return v;
}

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    unordered_map<int, int> m1, m2, m3;
    vector<int> v;
    for (int i = 0; i < n1; i++)
        m1[A[i]]++;
    for (int i = 0; i < n2; i++)
        m2[B[i]]++;
    for (int i = 0; i < n3; i++)
        m3[C[i]]++;

    for (int i = 0; i < n1; i++)
    {
        if (m1[A[i]] > 0 && m2[A[i]] > 0 && m3[A[i]] > 0)
        {
            v.push_back(A[i]);
            // Stopping to print the duplicates
            m1[A[i]] = 0;
        }
    }

    return v;
}

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> V;

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            if (find(V.begin(), V.end(), A[i]) == V.end())
            {
                V.push_back(A[i]);
            }
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else
            k++;
    }

    return V;
}