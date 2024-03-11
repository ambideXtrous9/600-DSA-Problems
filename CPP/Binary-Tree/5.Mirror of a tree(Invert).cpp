#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
1. do POSTORDER traversal
2. SWAP the nodes
*/

Node *invertTree(Node *root)
{
    if (!root)
        return NULL;

    invertTree(root->left);
    invertTree(root->right);

    swap(root->left, root->right);

    return root;
}