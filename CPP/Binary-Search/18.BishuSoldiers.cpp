#include <bits/stdc++.h>

using namespace std;


int idxSearchUB(int a[],int p,int n)
{
    int e = n-1;
    int s = 0;

    while(s<=e)
    {
        int mid = s + (e-s)/2;

        if(a[mid]==p) s = mid+1;
        else if(a[mid]<p) s = mid+1;
        else
            e = mid - 1;
    }
    return s;
}

int main()

{

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int p;

    int q;
    cin >> q;

    while (q--)
    {

        int cs = 0;
        cin >> p;
        int x = idxSearchUB(a,p,n);
        for (int i = 0; i < x; i++)
        {
            cs += a[i];
        }

        cout << x << " " << cs << endl;
    }

    return 0;
}
