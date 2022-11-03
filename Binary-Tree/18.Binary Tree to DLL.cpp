#include <bits/stdc++.h>

using namespace std;

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
1. we traverse the tree in INORDER manner
https://www.youtube.com/watch?v=O9Qd4jmyEiU&ab_channel=bool_fasle
*/



Node *BTtoDLL(Node *root, Node *&prev)
{
    if (!root)
        return root;
    
    Node *head = BTtoDLL(root->left, prev);

    if (prev == NULL)
        head = root;
    
    else   // DLL
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
   
    BTtoDLL(root->right, prev);
   
    return head;
}

Node *bToDLL(Node *root)
{
    Node *prev = NULL;
    return BTtoDLL(root, prev);
}