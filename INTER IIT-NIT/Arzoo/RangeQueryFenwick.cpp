#include <bits/stdc++.h>

using namespace std;

struct node
{
    int pos;
    int l;
    int r;
    int val;
};

bool comp(node a, node b)
{
    if (a.val == b.val)
        return a.l > b.l;

    return a.val > b.val;
}

void update(int *BIT, int n, int idx)
{
    while (idx <= n)
    {
        BIT[idx]++;
        idx += idx & (-idx);
    }
}

int query(int *BIT, int idx)
{
    int ans = 0;
    while (idx)
    {
        ans += BIT[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

// Function to solve the queries offline

void solveQuery(int arr[], int n, int QueryL[],int QueryR[], int QueryK[], int q)
{
    node a[n + q + 1];
    for (int i = 1; i <= n; ++i)
    {
        a[i].val = arr[i - 1];
        a[i].pos = 0;
        a[i].l = 0;
        a[i].r = i;
    }
    for (int i = n + 1; i <= n + q; ++i)
    {
        a[i].pos = i - n;
        a[i].val = QueryK[i - n - 1];
        a[i].l = QueryL[i - n - 1];
        a[i].r = QueryR[i - n - 1];
    }
    sort(a + 1, a + n + q + 1, comp);
    
    int BIT[n + 1];
    memset(BIT, 0, sizeof(BIT));
    
    int ans[q + 1];
    
    for (int i = 1; i <= n + q; ++i)
    {
        if (a[i].pos != 0)
        {
            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
            ans[a[i].pos] = cnt;
        }
        else
        {
            update(BIT, n, a[i].r);
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        cout << ans[i] << endl;
    }
}

int main()
{

    int arr[] = {7, 3, 9, 13, 5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    // 1-based indexing

    int QueryL[] = {1, 2};

    int QueryR[] = {4, 6};

    // k for each query

    int QueryK[] = {6, 8};

    // number of queries

    int q = sizeof(QueryL) / sizeof(QueryL[0]);

    // Function call to get

    solveQuery(arr, n, QueryL, QueryR, QueryK, q);

    return 0;
}