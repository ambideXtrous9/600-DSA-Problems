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

unordered_map<int, int> M;

TreeNode *build(vector<int> &in, vector<int> &pre, int &idx, int l, int r)
{
    if (l > r)
        return NULL;

    cout << idx << " ";

    TreeNode *root = new TreeNode(pre[idx--]);

    int inidx = M[root->val];

    root->right = build(in, pre, idx, inidx + 1, r);
    root->left = build(in, pre, idx, l, inidx - 1);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();

    for (int i = 0; i < n; i++)
    {
        M[inorder[i]] = i;
    }

    int l = 0;
    int r = n - 1;
    int idx = n - 1;

    return build(inorder, postorder, idx, l, r);
}