#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left = NULL;
    struct Node *right = NULL;
};

void inorder(Node *root, unordered_set<int> &store)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, store);
    store.insert(root->data);
    inorder(root->right, store);
}

int countPairs(Node *root1, Node *root2, int X)
{
    unordered_set<int> store1, store2;
    inorder(root1, store1);
    inorder(root2, store2);
    int count = 0;
    for (auto i : store1)
    {
        if (store2.find((X-i)) != store2.end())
        {
            count++;
        }
    }
    return count;
}