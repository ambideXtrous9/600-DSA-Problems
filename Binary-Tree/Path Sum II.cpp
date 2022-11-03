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

vector<vector<int>> ans;

void solve(TreeNode *root, vector<int> v, int k, int &sum)
{
    if (!root)
        return;

    k += root->val;

    v.push_back(root->val);

    if (k == sum && !root->left && !root->right)
    {
        ans.push_back(v);
        return;
    }

    solve(root->left, v, k, sum);
    solve(root->right, v, k, sum);
}
vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    ans.clear();

    vector<int> v;

    if (!root)
        return ans;

    int k = 0;
    solve(root, v, k, sum);
    return ans;
}