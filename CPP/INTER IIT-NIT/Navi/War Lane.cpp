#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    int d = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] > d)
            {
                d = a[i];
            }
            // if first soldier is the last soldier
            if (i == n - 1 && l - a[i] > d)
            {
                d = l - a[i];
            }
            // if more soldier are after him
            else
            {
                int x = ceil((float)(a[i + 1] - a[i]) / (float)2);
                d = max(x, d);
            }
        }
        else if (i == n - 1)
        {
            d = max(d, l - a[i]);
        }
        else
        { // for intermediate soldier
            int x = ceil((float)(a[i + 1] - a[i]) / (float)2);
            d = max(x, d);
        }
    }
    cout << d;
}
