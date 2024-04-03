#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
The diameter of a tree (sometimes called the width) is the number of nodes on the 
longest path between two end nodes.

The diameter of a tree T is the largest of the following quantities:

1. the diameter of T’s left subtree.
2. the diameter of T’s right subtree.
3. the longest path between leaves that goes through the root of T 
(this can be computed from the heights of the subtrees of T)
*/

int height(Node *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}
int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int dm = 1 + height(root->left) + height(root->right);

    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(dm, max(d2, d3));

    // Your code here
}

// Efficient

/*
Optimized implementation: The above implementation can be optimized by 
calculating the height in the same recursion rather than calling a height() separately. 
*/

// GFG
int height(Node *root, int &maxi)
{
    if (!root)
        return 0;

    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);

    int pass_above = 1 + max(lh, rh);

    int dia_via_this_node = lh + rh + 1;
    
    maxi = max(maxi, dia_via_this_node);

    return pass_above;
}

int diameter(Node *root)
{
    int maxi = 0;
    int h = height(root, maxi);
    return maxi;
}


// LC
int height(Node *root, int &maxi)
{
    if (!root)
        return 0;

    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);

    int pass_above = 1 + max(lh, rh);

    int dia_via_this_node = lh + rh + 1;
    
    maxi = max(maxi, dia_via_this_node);

    return pass_above;
}

int diameter(Node *root)
{
    int maxi = 0;
    int h = height(root, maxi);
    return maxi;
}