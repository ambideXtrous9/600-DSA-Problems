#include <bits/stdc++.h>

using namespace std;

vector<int> distributeCandies(int candies, int num_people)
{
    vector<int> V(num_people, 0);

    int x = 1;
    int i = 0;

    while (candies > 0)
    {

        if (candies < x) // about to end distribution
        {
            V[i % num_people] += candies; // give remaining to idx and end
            break;
        }

        V[i % num_people] += x; // give x candies to ith

        candies -= x; // reduce the candies count

        x++;          // candies to get next person
        i++;          // and index of next person
    }

    return V;
}