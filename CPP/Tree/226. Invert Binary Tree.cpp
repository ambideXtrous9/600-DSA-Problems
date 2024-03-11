#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* invertTree(Node* root) // postorder + swap(L,R)
    {
        if(!root) return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left,root->right);
        
        return root;
        
    }