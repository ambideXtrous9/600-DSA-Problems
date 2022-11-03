#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left  = NULL;
    struct Node *right = NULL;
};

string solve(Node *root, unordered_map<string, int> &M, vector<Node *> &V)
{
    if (!root)
        return "";

    string S = to_string(root->data) + "$" + solve(root->left, M, V) + "$" + solve(root->right, M, V);

    if (M[S] == 1)
        V.push_back(root);

    M[S]++;
    return S;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> V;
    unordered_map<string, int> M;

    solve(root, M, V);

    return V;
    // Code here
}