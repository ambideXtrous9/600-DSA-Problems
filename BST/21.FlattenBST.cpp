#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flat(TreeNode* root,TreeNode * &prev)
{
    if(!root) return;

    flat(root->right,prev);
    flat(root->left,prev);

    root->left = NULL;
    root->right = prev;

    prev = root;
}


void flatten(TreeNode *root)
{
    TreeNode* prev = NULL;
    flat(root,prev);
}


// Morris Order Traversal

// 1. if left exist goto right most node of LST and connect its right to cur node's right and 
// replace cur->right = cur->left
// and make cur->left = NULL
// move to right


TreeNode* BSTFlat(TreeNode* root)
{
    TreeNode* cur = root;

    while(cur)
    {
        if(cur->left)
        {
            TreeNode* prev = cur->left;

            while(prev->right)
            {
                prev = prev->right;
            }

            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }

        cur = cur->right;
    }

    return root;
}