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

TreeNode *LCA(TreeNode *root, int a, int b)
{
    if (!root)
        return NULL;

    if (root->val == a || root->val == b)
        return root;

    auto lca1 = LCA(root->left, a, b);
    auto lca2 = LCA(root->right, a, b);

    if (lca1 && lca2)
        return root;

    if (lca1)
        return lca1;

    return lca2;
}

bool DFS(TreeNode *root, int a, string &str)
{
    if (!root)
        return false;

    if (root->val == a)
    {
        return true;
    }

    str.push_back('L');
    auto l = DFS(root->left, a, str);

    if (l)
        return true;
    str.pop_back();

    str.push_back('R');
    auto r = DFS(root->right, a, str);

    if (r)
        return true;
    str.pop_back();

    return false;
}

string getDirections(TreeNode *root, int a, int b)
{
    string str1 = "";
    string str2 = "";

    root = LCA(root, a, b);

    DFS(root, a, str1);
    DFS(root, b, str2);

    cout << str1 << " " << str2 << endl;

    for (auto &c : str1)
        c = 'U';

    return str1 + str2;
}