#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left = NULL;
    struct Node *right = NULL;
};

int sum(Node *root, int &res)
{
    if (!root)
        return 0;

    int l = sum(root->left, res);
    int r = sum(root->right, res);

    int take_child = root->data + max(l, r);
    int not_take_child = root->data;

    int ans_path = root->data + l + r;

    res = max({res, ans_path, take_child, not_take_child});

    return max(take_child, not_take_child);
}

int findMaxSum(Node *root)
{
    int res = INT_MIN;

    sum(root, res);

    return res;
}