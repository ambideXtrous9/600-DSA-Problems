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
DP Approach by -> Take and Not Take
*/

int sum(Node* root,unordered_map<Node*,int> &dp)
{
    if(!root) return 0;

    if(dp[root]) return dp[root];

    // take the root

    int val1 = root->data;

    if(root->left)
    {
        val1 += sum(root->left->left,dp);
        val1 += sum(root->left->right,dp);
    }
    if(root->right)
    {
        val1 += sum(root->right->left,dp);
        val1 += sum(root->right->right,dp);
    }

    // not take the root
    int val2 = sum(root->left,dp) + sum(root->right,dp);

    return dp[root] = max(val1,val2);

}