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

void inorder(Node *root, int &k, int &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, k, ans);

    k--;

    if (k == 0)
    {
        ans = root->data;

        return;
    }

    inorder(root->right, k, ans);
}

int KthSmallestElement(Node *root, int k)
{
    int ans = -1;

    inorder(root, k, ans);

    return ans;
    // add code here.
}