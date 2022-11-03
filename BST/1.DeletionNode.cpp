#include <bits/stdc++.h>

using namespace std;

// structure of the node
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

struct Node *InorderSuccessor(struct Node *node)
{
    struct Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int data)
{
    // base case
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else // target found
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;
        
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        else
        {
            struct Node *Successor = InorderSuccessor(root->right);
            root->data = Successor->data;
            root->right = deleteNode(root->right, Successor->data);
        }
    }
    return root;
}

// create the Node and return its address
struct Node *createNode(int val)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = val;
    return NewNode;
}

struct Node *insertValue(struct Node *root, int value) // BST construction
{
    if (root == NULL) // if root is null make the node as root
    {
        root = new Node(value);
        return root;
    }
    if (value < root->data) // if val is less then current node val then add it in LST
    {
        root->left = insertValue(root->left, value);
    }
    if (value > root->data) // if val is > current node val then put it in RST
    {
        root->right = insertValue(root->right, value);
    }

    return root; // atlast return the root;
}

void InOrder(struct Node *root) // inorder gives sorted order output of the BST
{
    if (root)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}
// left most element of a node is minimum one among all its children
struct Node *getMinimumdata(struct Node *curr)
{
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// searching for the target node
void searchdata(struct Node *&curr, int data, struct Node *&parent)
{
    while (curr != NULL && curr->data != data)
    {
        parent = curr;

        if (data < curr->data) // if data is less than current node then search in lst
        {
            curr = curr->left;
        }
        else // else search in rst
        {
            curr = curr->right;
        }
    }
}

// to delete there are 3 cases:
// 1. target node is a leaf
// 2 target node has 2 children
// 3. target node has only single child

void deleteNodeIter(struct Node *&root, int data)
{
    struct Node *parent = NULL;

    struct Node *curr = root;

    searchdata(curr, data, parent); // search for the target node

    if (curr == NULL) // when BST is empty
    {
        return;
    }

    if (curr->left == NULL && curr->right == NULL) // if the target node is leaf
    {
        if (curr != root)
        {
            if (parent->left == curr) // if it is left then make it NULL
            {
                parent->left = NULL;
            }
            else // if it is right then make right child NULL
            {
                parent->right = NULL;
            }
        }

        else // if root is the target node
        {
            root = NULL;
        }

        free(curr);
    }

    else if (curr->left && curr->right) // when target node has 2 children i.e internal node with deg = 3
    {

        struct Node *successor = getMinimumdata(curr->right); // find minimum from the right sub tree

        int val = successor->data;

        deleteNodeIter(root, successor->data); // and deleting it from the previous postion

        curr->data = val; // placing the successor in the deleted position
    }

    else // when target Node has single child
    {
        struct Node *child = NULL;

        if (curr->left) // if only left child exist
            child = curr->left;
        else
            child = curr->right; // if only right child exist

        if (curr != root)
        {
            if (parent->left == curr) // if target node is left child of its parent
            {
                parent->left = child; // putiing curr's child as its parent's child by skiiping it
            }
            else // same for the right
            {
                parent->right = child;
            }
        }

        else // if the target node is root itself
        {
            root = child; // then make child as the new root
        }
        free(curr); // free the space of the target node
    }
}
