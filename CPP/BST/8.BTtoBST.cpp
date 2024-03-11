#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder_of_tree(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inorder_of_tree(root->left, v);
    v.push_back(root->data);
    inorder_of_tree(root->right, v);
}
void inorder_bst(Node *root, vector<int> v, int &i)
{
    if (!root)
        return;
    inorder_bst(root->left, v, i);
    root->data = v[i++];
    inorder_bst(root->right, v, i);
    // return root;
}
Node *binaryTreeToBST(Node *root)
{
    // Your code goes here
    vector<int> v;
    int i = 0;
    inorder_of_tree(root, v);
    sort(v.begin(), v.end());
    inorder_bst(root, v, i);
    return root;
}

struct Node *createNode(int val)
{
    struct Node *NewNode = new Node(val);
    return NewNode;
}

struct Node *insertValue(struct Node *root, int value) // BST construction
{
    struct Node *node = createNode(value); // create the node with the value first

    if (root == NULL) // if root is null make the node as root
    {
        root = node;
        return root;
    }
    if (value < root->data) // if val is less then current node val then add it in LST
    {
        root->left = insertValue(root->left, value);
    }
    else // if val is > current node val then put it in RST
    {
        root->right = insertValue(root->right, value);
    }

    return root; // atlast return the root;
}

void Construct(Node *root, Node *&head)
{
    if (!root)
        return;

    head = insertValue(head, root->data);

    Construct(root->left, head);
    Construct(root->right, head);
}

Node *binaryTreeToBST(Node *root)
{
    Node *head = NULL;
    Construct(root, head);

    return head;
    // Your code goes here
}