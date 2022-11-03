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