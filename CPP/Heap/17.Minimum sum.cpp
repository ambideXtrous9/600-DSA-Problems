#include <bits/stdc++.h>

using namespace std;

string solve(int arr[], int n)
{
    sort(arr, arr + n, greater<>());

    string s = "";
    int c = 0;

    for (int i = 0; i < n; i += 2)
    {
        int sum = arr[i] + c;

        if (i + 1 < n)
            sum += arr[i + 1];

        c = sum / 10;

        s += to_string(sum % 10);
    }
    s += to_string(c);

    while (s.back() == '0')
        s.pop_back();

    reverse(s.begin(), s.end());

    return s;
    // code here
}

string solve(int arr[], int n)
{
    priority_queue<int> H;

    for (int i = 0; i < n; i++)
        H.push(arr[i]);

    int carry = 0;
    string S = "";
    while (H.size() > 1)
    {
        int x = H.top();
        H.pop();
        int y = H.top();
        H.pop();

        x = x + y + carry;
        S += to_string(x % 10);
        carry = x / 10;
    }

    if (!H.empty())
    {
        int x = H.top();
        H.pop();

        x = x + carry;
        carry = x / 10;

        S += to_string(x % 10);
    }

    if (carry)
        S += to_string(carry);

    while (S.back() == '0')
        S.pop_back();

    reverse(S.begin(), S.end());

    return S;
    // code here
}