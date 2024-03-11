#include <bits/stdc++.h>

using namespace std;

int get_count(int n)
{
    int cnt = 0;
    while (n >= 5)
    {
        cnt = cnt + (n / 5);
        n = n / 5;
    }
    return cnt;
}
int findNum(int n)
{

    int low = 0, high = 1e9, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cnt = get_count(mid);
        if (cnt >= n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}