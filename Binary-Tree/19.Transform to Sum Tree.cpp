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

int solve(Node *root)
{
    if (!root)
        return 0;

    int x = root->data;

    int l = solve(root->left);
    int r = solve(root->right);

    root->data = l + r;

    return l + r + x;
}
void toSumTree(Node *node)
{
    int x = solve(node);
}