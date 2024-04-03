#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left = NULL;
    struct Node *right = NULL;
};

void inorder(Node *root, int l, int h, int &count)
{
    if (!root)
        return;

    inorder(root->left, l, h, count);

    if (root->data <= h && root->data >= l)
        count++;

    inorder(root->right, l, h, count);
}

int getCount(Node *root, int l, int h)
{
    int count = 0;
    inorder(root, l, h, count);
    return count;
}

int getCount(Node *root, int l, int h)
{
    if (root == NULL)
        return 0;

    if (root->data >= l && root->data <= h)
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    else
        return getCount(root->left, l, h) + getCount(root->right, l, h);
}