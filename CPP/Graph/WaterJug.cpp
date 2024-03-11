#include <bits/stdc++.h>

using namespace std;

int step = 0;

bool BFS(int x, int y, int z)
{
    if (x + y < z)
        return false;

    int dx[] = {x, -x, y, -y};

    unordered_map<int, bool> vis;
    queue<int> Q;

    Q.push(0);
    vis[0] = true;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        if (u == z)
            return true;

        for (auto p : dx)
        {
            int v = u + p;

            if (v == z)
                return true;

            if (v < 0 || v > x + y)
                continue;

            if (!vis[v])
            {
                Q.push(v);
                vis[v] = true;
            }
        }
        step++;
    }
    return false;
}

int main()
{
    int Jug1 = 3, Jug2 = 5, target = 4;
    cout << "Path from initial state "
            "to solution state ::\n";
    cout<<BFS(Jug1, Jug2, target)<<endl;
    cout<<step<<endl;
    return 0;
}