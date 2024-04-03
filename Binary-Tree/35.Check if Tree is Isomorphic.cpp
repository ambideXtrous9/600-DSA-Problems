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
Two trees are called isomorphic if one can be obtained from another by a series of flips,
i.e. by swapping left and right children of several nodes. 
Any number of nodes at any level can have their children swapped. 
Two empty trees are isomorphic.
*/

bool isIsomorphic(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;

    return (root1->data == root2->data) && ((isIsomorphic(root1->left, root2->left) &&
                                             isIsomorphic(root1->right, root2->right)) ||
                                            (isIsomorphic(root1->left, root2->right) &&
                                             isIsomorphic(root1->right, root2->left)));
}