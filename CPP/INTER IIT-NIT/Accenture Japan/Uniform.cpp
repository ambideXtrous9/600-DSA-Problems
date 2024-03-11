#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m1, m2, m3, m4;

    cin >> n >> m1 >> m2 >> m3 >> m4;

    vector<string> s;
    vector<string> m;
    vector<string> l;
    vector<string> x;

    while (n--)
    {
        string str;
        int a;

        cin >> str >> a;

        if (a >= m1 && a < m2)
            s.push_back(str);

        else if (a >= m2 && a < m3)
            m.push_back(str);

        else if (a >= m3 && a < m4)
            l.push_back(str);

        else
            x.push_back(str);
    }

    cout << "S:" << endl;
    for (auto p : s)
        cout << p << endl;

    cout << "M:" << endl;
    for (auto p : m)
        cout << p << endl;

    cout << "L:" << endl;
    for (auto p : l)
        cout << p << endl;

    cout << "X:" << endl;
    for (auto p : x)
        cout << p << endl;

    return 0;
}