#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int size(Node *root)
{
    if (!root)
        return 0;

    return 1 + size(root->left) + size(root->right);
}
bool isCompleteUtil(struct Node *root, int i, int n)
{
    if (!root)
        return true;

    // If index assigned to
    // current node is more than
    // number of nodes in tree,
    // then tree is not complete
    if (i >= n)
        return false;

    // Recur for left and right subtrees
    return (isCompleteUtil(root->left, 2 * i + 1, n) && isCompleteUtil(root->right, 2 * i + 2, n));
}

bool isHeap2(struct Node *tree)
{
    if (tree == NULL)
        return true;

    if (tree->left == NULL && tree->right == NULL)
        return true;

    if (tree->right == NULL) // in heap L must exist before R i.e must be complete
        return tree->left->data < tree->data;

    return (tree->left->data < tree->data && tree->right->data < tree->data) && isHeap2(tree->left) && isHeap2(tree->right);
    // code here
}
bool isHeap(struct Node *tree)
{
    int i = 0;
    int n = size(tree);

    return isCompleteUtil(tree, i, n) && isHeap2(tree);
}