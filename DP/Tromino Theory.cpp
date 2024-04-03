#include <bits/stdc++.h>

using namespace std;

// LC 790. Domino and Tromino Tiling

/*
Intuition:
After reading the question we get a intuition of doing recursion and dp .Now those of you who got intuition as recursion you are not wrong but you'r code will be one of the most unoptimized code. So let's discuss when to use a dp ,If the two case are confirmed in a problem then you can use dp

If it has overlapping sub problems
If optimizing the sub problems wll optimize the whole question
Both the above the condition are satisfied in this question. So now let's discuss the approach :)
Algorithm:

Wheneve we put a domino or tromino we are either left out with a whole rectangle or with a rectangle + left alone square [lonely doge]
So to fill out the whole rectangle the number of ways can be i*2and to fill a lonely doge the number of ways is to fill a rectangle of size i*2 + one square sticking out.
Whenever we use a domino tile we are either left with a full rectangle of size i-1 or with a full rectangle of size i-2 . This leads to formulation of domino that is Domino[i] = Domino[i-1] + Domino[1-2]
Now let's think we put out a tromino first then we are left with lonely doge .so the size of that lonely doge is i-2 . Also tromino is non symmetric in shape so it has two orientaions which leads to 2(i-2).
This makes our end conclusion for dominoDomino=Domino[i] = Domino[i-1] + Domino[1-2] + 2 * Tromino[i-2]
Let's continue with tromino i.e whenever we use it we are left alone with a lonely doge so to fill that we got two options
put a domino leaving us all again with a left alone square again .This gives Tromino[i-1]
The second option is put tromino aligning with lonely doge and completing them as a whole rectangle. A happy endng we all want .Btw this gives Domino[i-1]
6.Thus to conclude this ,the formula will be Tromino[i]=Tromino[i-1]+Domino[i-1]
7.And now again ... ok you thought something is remaining, lol the problem is solved .KABOOM
*/

int mod = 1e9 + 7;
int solve(int n)
{
    if (n < 3)
        return n;

    vector<long long int> D(n + 1, 0);
    vector<long long int> T(n + 1, 0);

    D[0] = 0;
    D[1] = 1;
    D[2] = 2;
    T[0] = 0;
    T[1] = 1;
    T[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        D[i] = (D[i - 1] + D[i - 2] + 2 * T[i - 2]) % mod;
        T[i] = (T[i - 1] + D[i - 1]) % mod;
    }

    return D[n];
}