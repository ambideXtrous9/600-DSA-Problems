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


TreeNode *BuildBST(vector<int> preorder, int &idx, int bound)
{
    if (idx >= preorder.size() || preorder[idx]>bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[idx++]);
    root->left = BuildBST(preorder, idx, root->val);
    root->right = BuildBST(preorder, idx, bound);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int idx = 0;
    return BuildBST(preorder,idx,INT_MAX);
}

TreeNode *BuildBST(vector<int> preorder, int &idx, int s, int e, unordered_map<int, int> &M)
{
    if (s > e)
        return NULL;

    TreeNode *root = new TreeNode(preorder[idx++]);

    int inidx = M[root->val];

    root->left = BuildBST(preorder, idx, s, inidx - 1, M);
    root->right = BuildBST(preorder, idx, inidx + 1, e, M);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    vector<int> pre(preorder.begin(), preorder.end());
    int n = pre.size();

    sort(preorder.begin(), preorder.end());

    unordered_map<int, int> M;

    for (int i = 0; i < preorder.size(); i++)
    {
        M[preorder[i]] = i;
    }

    int idx = 0;

    return BuildBST(pre, idx, 0, n - 1, M);
}

int search(vector<int> arr,int val,int s,int e)
{
    for(int i=s;i<=e;i++)
    {
        if(arr[i]==val) return i;
    }
}

TreeNode *BuildBST(vector<int> preorder, vector<int> inorder,int &idx, int s, int e)
{
    if (s > e)
        return NULL;

    TreeNode *root = new TreeNode(preorder[idx++]);

    int inidx = search(inorder,root->val,s,e);

    root->left = BuildBST(preorder, inorder,idx, s, inidx - 1);
    root->right = BuildBST(preorder, inorder,idx, inidx + 1, e);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    int idx = 0;
    return BuildBST(preorder,inorder,idx,0,n-1);
}