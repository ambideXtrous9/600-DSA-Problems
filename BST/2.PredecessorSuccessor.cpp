#include <bits/stdc++.h>

using namespace std;

// structure of the node
struct Node
{
    int key;
    struct Node *left  = NULL;
    struct Node *right = NULL;
};

void inorder_successor(Node *root, Node *&succ, int key)
{
    while (root != NULL)
    {
        if (root->key <= key)
        {
            root = root->right;
        }
        else if (root->key > key)
        {
            succ = root;
            root = root->left;
        }
    }
}

void inorder_predecessor(Node *root, Node *&pred, int key)
{
    while (root != NULL)
    {

        if (root->key >= key)
        {
            root = root->left;
        }
        else if (root->key < key)
        {
            pred = root;
            root = root->right;
        }
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    inorder_successor(root, suc, key);
    inorder_predecessor(root, pre, key);
}