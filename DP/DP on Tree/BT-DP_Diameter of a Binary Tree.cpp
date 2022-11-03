#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int d(Node *root, int &res)
{
    if (!root)
        return 0;

    int l = d(root->left, res);
    int r = d(root->right, res);

    res = max(res, 1 + l + r);

    return 1 + max(l, r);
}

int diameter(Node *root)
{
    int res = INT_MIN;

    d(root, res);

    return res;
}