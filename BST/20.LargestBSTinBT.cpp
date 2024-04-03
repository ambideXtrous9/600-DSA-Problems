#include <bits/stdc++.h>

using namespace std;

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


/*

1. The left and right subtrees of every tree node are BST.

2. A node’s value should be more than the largest value in the left subtree 
and less than the smallest value in the right subtree.


{Largest from SubTree, Smallest from SubTree, isBST, size}

*/
vector<int> LargestBST(Node *root, int &ans)
{
    if (!root)
        
        // {Largest from ST, Smallest from ST, isBST, size}

        return {INT_MIN, INT_MAX, 1, 0};
    
    vector<int> L = LargestBST(root->left, ans);
    vector<int> R = LargestBST(root->right, ans);

    vector<int> cur;
    
    /* for parent node, we have to populate 4 things :

        1. maxNode = max(root itself, max from Right)
        2. minNode = min(root itself, min from Left)
    
    */

    cur.push_back(max(root->data, R[0])); 
    cur.push_back(min(root->data, L[1]));

    /*
    A node’s value should be more than the largest value in the left subtree 
    and less than the smallest value in the right subtree.
    */
    
    if (R[2] && L[2] && root->data > L[0] && root->data < R[1])
        cur.push_back(1); // isBST
    else
        cur.push_back(0);
    
    cur.push_back(1 + L[3] + R[3]); // size of BST at cur node
    
    if (cur[2])
        ans = max(ans, cur[3]);
    
    return cur;
}

int largestBst(Node *root)
{
    int ans = INT_MIN;
    vector<int> V = LargestBST(root, ans);
    return ans;
    // Your code here
}