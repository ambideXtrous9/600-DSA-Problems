#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left = NULL;
    struct TreeNode *right = NULL;
};

void inorder(TreeNode *root, vector<TreeNode *> &V)
{
    if (!root)
        return;

    inorder(root->left, V);

    V.push_back(root);

    inorder(root->right, V);
}

TreeNode *BBST(vector<TreeNode *> V, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;

    TreeNode *root = V[mid];

    root->left = BBST(V, s, mid - 1);
    root->right = BBST(V, mid + 1, e);

    return root;
}

TreeNode *buildBalancedTree(TreeNode *root)
{
    vector<TreeNode *> V;
    inorder(root, V);

    int n = V.size();
    return BBST(V, 0, n - 1);
}