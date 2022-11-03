#include <bits/stdc++.h>

using namespace std;

/*
Brute force : A simple way to make all elements equal is that at each step find
the largest elements and then increase all rest n-1 elements by 1.
We should keep doing this operation till all elements become equal.
Time Complexity : O(n^2)
*/

/*
We have to increment n-1 elements by 1 to make them equal.
This is equal to decrementing only 1 element by 1.
Since we need to make all the elements equal we can consider
the given problem to be equal to decrementing all the elements by 1 in each move
until they are equal to the minimum element in the array.

For example- [5,6,7,8] can be made equal if we decrement number 8,
three times and 7, two times and 6 one times. Decrementing 8 by 1 is equal to adding 1 to
all the other elements.
Conclusion - We are just reversing the problem to make it simpler :)
*/

int minMoves(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();

    int mn = INT_MAX;

    for (auto x : nums)
    {
        mn = min(mn, x);
        sum += x;
    }

    return sum - n * (mn);
}