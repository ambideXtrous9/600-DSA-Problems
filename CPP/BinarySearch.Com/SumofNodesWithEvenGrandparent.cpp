#include <bits/stdc++.h>

using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};

void getSum(Tree *curr, Tree *p, Tree *gp, int &sum)
{
    if (curr == NULL)
        return;

    if (gp != NULL && gp->val % 2 == 0)
        sum += curr->val;

    getSum(curr->left, curr, p, sum);

    getSum(curr->right, curr, p, sum);
}

int solve(Tree *root)
{
    int sum = 0;
    getSum(root, NULL, NULL, sum);
    return sum;
}