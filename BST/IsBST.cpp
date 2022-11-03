#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left = NULL;
    struct Node *right = NULL;
};

bool isBST(Node* root,Node* L,Node* R)
{
    if(!root) return true;

    if(L && L->data >= root->data) return false;
    if(R && R->data <= root->data) return false;

    return isBST(root->left,L,root) && isBST(root->right,root,R);
}