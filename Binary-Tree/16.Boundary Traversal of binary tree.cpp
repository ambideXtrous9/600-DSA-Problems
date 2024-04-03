#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/*

add root to res vector.

1. Discover Left Boundary First.
2. Then Leaves
3. At Last Right Boundary from bottom to top manner.

*/

bool isLeaf(Node *root)
{
    if (!root)
        return false;
    else if (!root->left && !root->right)
        return true;
    else
        return false;
}


/*
1. move to left and then start traversal
2. push the cur to res if it is not a leaf
3. if left exist move to left
4. else move to right.
*/

void LB(Node *root, vector<int> &V)
{
    if (!root)
        return;
    
    Node *cur = root->left;
    
    while (cur)
    {
        if (!isLeaf(cur))
            V.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

/*
1. move to right and then start traversal
2. push the cur to stack(as we need in bottom to up manner) if it is not a leaf
3. if right exist move to right
4. else move to left.
5. dump stack to res vector.
*/
void RB(Node *root, vector<int> &V)
{
    if (!root)
        return;
    stack<int> S;
    Node *cur = root->right;
    while (cur)
    {
        if (!isLeaf(cur))
            S.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!S.empty())
    {
        V.push_back(S.top());
        S.pop();
    }
}

/*
1. traverse the tree in preorder
2. if leaf store it to res vector.
*/
void LEAF(Node *root, vector<int> &V)
{
    if (!root)
        return;
    if (isLeaf(root))
    {
        V.push_back(root->data);
        return;
    }
    if (root->left)
        LEAF(root->left, V);
    if (root->right)
        LEAF(root->right, V);
}
vector<int> boundary(Node *root)
{
    vector<int> V;
    if (!root)
        return V;
    
    V.push_back(root->data);
    
    if (isLeaf(root))
        return V;

    LB(root, V);
    LEAF(root, V);
    RB(root, V);
    
    return V;
}