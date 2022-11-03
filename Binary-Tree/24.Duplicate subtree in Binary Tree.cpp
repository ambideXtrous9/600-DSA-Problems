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
Given a binary tree, find out whether it contains a 
duplicate sub-tree of size two or more, or not.
*/

string solve(Node *root, unordered_map<string, int> &M)
{
    if (!root)
        return "$";

    if (!root->left && !root->right)
    {
        string S = to_string(root->data);
        return S;
    }

    string ls = solve(root->left, M);
    string rs = solve(root->right, M);

    string S = to_string(root->data) + ls + rs;

    M[S]++;
    return S;
}
int dupSub(Node *root)
{

    unordered_map<string, int> M;

    solve(root, M);

    for (auto x : M)
    {
        if (x.second >= 2)
            return 1;
    }
    return 0;
}