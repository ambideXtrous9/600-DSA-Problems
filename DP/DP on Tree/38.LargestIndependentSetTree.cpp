#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    int liss;
    struct node *left, *right;
};

int LISS(struct node *root)
{
    if (root == NULL)
       return 0;
 
    // Calculate size excluding the current node
    int size_excl = LISS(root->left) + LISS(root->right);
 
    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
       size_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
       size_incl += LISS(root->right->left) + LISS(root->right->right);
 
    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}
 
// A memoization function returns size of the largest independent set in
//  a given binary tree
int LISS(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->liss)
        return root->liss;
    if (root->left == NULL && root->right == NULL)
        return (root->liss = 1);
    int liss_excl = LISS(root->left) + LISS(root->right);
    int liss_incl = 1;
    if (root->left)
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
        liss_incl += LISS(root->right->left) + LISS(root->right->right);
    root->liss = max(liss_incl, liss_excl);
    return root->liss;
}