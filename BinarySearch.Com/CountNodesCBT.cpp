#include <bits/stdc++.h>

using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};

int solve(Tree* root) 
{
    if(!root) return 0;

    return 1 + solve(root->left) + solve(root->right);
    
}