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

vector<int> preorderTraversal(TreeNode *root)
{
    // Morris Traversal O(1)
    vector<int> preorder;
    TreeNode *cur = root;

    while (cur)
    {
        if (cur->left == NULL)
        {
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;

            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur; // making the thread
                preorder.push_back(cur->val);
                cur = cur->left; // moving left
            }
            else
            {
                prev->right = NULL; // cutting the thread
                cur = cur->right; // moving right
            }
        }
    }

    return preorder;
}