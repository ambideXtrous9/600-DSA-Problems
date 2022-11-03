#include <bits/stdc++.h>

using namespace std;
/*
1. Create an array arr[] of size N, where N is the number of nodes in the given BST.
2. Perform the inorder traversal of the BST store values in the arr[] in sorted order.
3. Now perform the preorder traversal of the tree.
4. While traversing the root during the preorder traversal, one by one copy the values from the array arr[] to the nodes of the BST.
*/
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

void inorderTraversal(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;

    // first recur on left subtree
    inorderTraversal(root->left, arr);

    // then copy the data of the node
    arr.push_back(root->data);

    // now recur for right subtree
    inorderTraversal(root->right, arr);
}

void BSTToMinHeap(Node *root, vector<int> arr, int &i)
{
    if (root == NULL)
        return;

    // first copy data at index 'i' of 'arr' to
    // the node
    root->data = arr[i++];

    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);

    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}

// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node *root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> arr;
    int i = 0;

    // inorder traversal to populate 'arr'
    inorderTraversal(root, arr);

    // BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, i);
}