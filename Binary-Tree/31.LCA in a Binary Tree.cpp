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
1. Find a path from the root to n1 and store it in a vector or array. 
2. Find a path from the root to n2 and store it in another vector or array. 
3. Traverse both paths till the values in arrays are the same. Return the common element just before the mismatch. 
*/


/*
The idea is to traverse the tree starting from the root. 
If any of the given keys (n1 and n2) matches with the root,
then the root is LCA (assuming that both keys are present). 
If the root doesn’t match with any of the keys, we recur for the left and right subtree. 
The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. If both keys lie in the left subtree, then the left subtree has LCA also, otherwise, LCA lies in the right subtree.  
*/

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *LCA = lca(root->left, n1, n2);
    Node *RCA = lca(root->right, n1, n2);

    if (LCA && RCA)
        return root;
    if (LCA)
        return LCA;
    return RCA;
}