#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left = NULL;
    struct TreeNode *right = NULL;
};

void inorder(TreeNode *root, vector<TreeNode *> &V)
{
    if (!root)
        return;

    inorder(root->left, V);

    V.push_back(root);

    inorder(root->right, V);
}

vector<TreeNode*> MergeSortedArray(vector<TreeNode*> V1,vector<TreeNode*> V2)
{
    int m = V1.size();
    int n = V2.size();

    vector<TreeNode*> V(m+n);

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<m && j<n)
    {
        if(V1[i]->data < V2[j]->data)
        {
            V[k++] = V1[i++];
        }
        else
            V[k++] = V2[j++];
    }

    while(i<m)
    {
        V[k++] = V1[i++];
    }

    while(j<n)
    {
        V[k++] = V2[j++];;
    }

    return V;

}

TreeNode *BBST(vector<TreeNode *> V, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;

    TreeNode *root = V[mid];

    root->left = BBST(V, s, mid - 1);
    root->right = BBST(V, mid + 1, e);

    return root;
}

TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2, int m, int n)
{
    vector<TreeNode*> V1;
    vector<TreeNode*> V2;

    inorder(root1,V1);
    inorder(root2,V2);

    vector<TreeNode*> V = MergeSortedArray(V1,V2);

    TreeNode* root = BBST(V,0,V.size()-1);

    return root;
}