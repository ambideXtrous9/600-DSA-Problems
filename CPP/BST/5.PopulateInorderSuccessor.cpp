#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left = NULL;
    struct Node *right = NULL;
    struct Node *next = NULL;
};

void inorder(Node *root, vector<Node *> &v)
{
    if (!root)
    {
        return;
    }

    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}

void populateNext(Node *root)
{
    vector<Node *> v;
    inorder(root, v);
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        v[i]->next = v[i + 1];
    }
}

void inorder(Node *root, Node *&prev)
{
    if (root == NULL)
        return;

    inorder(root->left, prev);

    if (prev != NULL)
    {
        prev->next = root;
    }

    prev = root;
    inorder(root->right, prev);
}

void populateNext(Node *root)
{
    Node *prev = NULL;
    inorder(root, prev);
}