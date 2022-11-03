#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int height(Node *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    if (lh == -1)
        return -1;
    int rh = height(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(Node *root)
{
    int x = height(root);
    
    return x!=-1;
    //  Your Code here
}


//=============================================================
// O(N^2)

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}

bool isBalanced(Node *root)
{
    if (root == nullptr)
        return true;
    else
    {
        int leftH = height(root->left);
        int rightH = height(root->right);

        int diff = abs(rightH - leftH);
        
        return diff <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
}
