#include <bits/stdc++.h>

using namespace std;

// next greatest to left and if not exist put the val[i] itself,
// same for right also,
// now keep on adding -> ans += min(L[i],R[i]) - arr[i]

vector<int> NGRSTL(int arr[], int n)
{
    vector<int> V(n, 0);

    V[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        V[i] = max(V[i - 1], arr[i]);
    }

    return V;
}

vector<int> NGRSTR(int arr[], int n)
{
    vector<int> V(n, 0);

    V[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        V[i] = max(V[i + 1], arr[i]);
    }

    return V;
}

long long trappingWater(int arr[], int n)
{

    vector<int> L = NGRSTL(arr, n);
    vector<int> R = NGRSTR(arr, n);

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {

        ans += (min(L[i], R[i]) - arr[i]);
    }

    return ans;
}