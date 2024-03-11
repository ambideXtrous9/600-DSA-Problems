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

TreeNode *BuildBST(vector<int> preorder, vector<int> inorder, int &idx, int s, int e)
{
    if (s > e)
        return NULL;

    TreeNode *root = new TreeNode(preorder[idx++]);

    int inidx = M[root->val];

    root->left = BuildBST(preorder, inorder, idx, s, inidx - 1);
    root->right = BuildBST(preorder, inorder, idx, inidx + 1, e);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    int idx = 0;

    for (int i = 0; i < n; i++)
        M[inorder[i]] = i;

    return BuildBST(preorder, inorder, idx, 0, n - 1);
}

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/*
BC : l<r

1. build the root node using first node of PREORDER and do it preorder manner
2. now find the index of the node in inorder array
3. now recur for rest.
*/

int preidx = 0;

Node *CTree(int in[], int pre[], int l, int r)
{
    if (l > r)
        return NULL;
    Node *root = new Node(pre[preidx++]);

    int inidx;

    for (int i = l; i <= r; i++)
    {
        if (in[i] == root->data)
        {
            inidx = i;
            break;
        }
    }
    root->left = CTree(in, pre, l, inidx - 1);
    root->right = CTree(in, pre, inidx + 1, r);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int l = 0;
    int r = n - 1;

    Node *head = CTree(in, pre, l, r);
    return head;
}