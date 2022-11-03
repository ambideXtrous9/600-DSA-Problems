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

void MorrisOrderTraversal(Node *root)
{
    vector<int> inorder;
    Node *cur = root;

    while (cur)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node *prev = cur->left;

            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur; // making the thread
                cur = cur->left;   // moving left
            }
            else
            {
                prev->right = NULL; // cutting the thread
                inorder.push_back(cur->data);
                cur = cur->right; // moving right
            }
        }
    }
}