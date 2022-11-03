#include <bits/stdc++.h>

using namespace std;

int func(int X, int Y)
{
    int to_add = 0;
    if (X % Y != 0)
    {
        to_add = Y - (X % Y);
    }
    else
        to_add = 0;
    int allowed = 1;
    while (to_add >= allowed)
    {
        X = X * 10;
        if (X % Y != 0)
        {
            to_add = Y - (X % Y);
        }
        else
            to_add = 0;
        allowed *= 10;
    }
    return X + to_add;
}

int main()
{
    int X = func(50, 7);

    cout << X << endl;

    return 0;
}
