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
1. find LCA of given Nodes.
2. find dist LCA to N1 and dist LCA to N1 using DFS/BFS
3. now add => dist1 + dist2 - 2
*/


int dfs(Node *root,int tar)
    {
        if(!root)return 0;
        
        if(root->data==tar)return 1;
        
        int left=dfs(root->left,tar);
        if(left)return 1+left;
        
        int right=dfs(root->right,tar);
        if(right)return 1+right;
        
    }
    Node *lca(Node *root,int a,int b)
    {
        if(!root)return NULL;
        
        if(root->data==a || root->data==b)return root;
        
        Node *left=lca(root->left,a,b);
        Node *right=lca(root->right,a,b);
        
        if(left && right)return root;
        
        else if(left) return left;
        
        else return right;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node *l=lca(root,a,b);
        int l1=dfs(l,a);
        int l2=dfs(l,b);
        
        return l1+l2-2;
    }