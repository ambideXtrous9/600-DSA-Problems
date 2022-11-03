#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 1. preorder traverse the tree
// 2. for every recursion call apart from the parent node also pass the maximum value seen so far
// 3. if the current node value is greater or equal to maximum seen till now then increase count and update that maximum


void preorder(TreeNode *root, int mx, int &ans)
{
    if (!root)
        return;

    if (root->val >= mx)
    {
        mx = root->val;
        ans++;
    }

    preorder(root->left, mx, ans);
    preorder(root->right, mx, ans);
}
int goodNodes(TreeNode *root)
{
    int ans = 0;
    int mx = INT_MIN;

    preorder(root, mx, ans);

    return ans;
}