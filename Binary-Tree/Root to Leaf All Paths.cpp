#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* The function should print all the paths from root
 to leaf nodes of the binary tree */

void inorder(Node* root,vector<int> arr,vector<vector<int>> &V)
{
    if(!root) return;
    
    arr.push_back(root->data);
    
    if(!root->left && !root->right)
    {
        V.push_back(arr);
    }
    
    inorder(root->left,arr,V);
    inorder(root->right,arr,V);
}


vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> V;
    vector<int> arr;
    
    inorder(root,arr,V);
    
    return V;
    // Code here
}