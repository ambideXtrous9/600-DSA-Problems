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

string solve(Node* root,unordered_map<string,int> &M,vector<Node*> &V)
{
    if(!root) return "";
    
    string ls = solve(root->left,M,V);
    string rs = solve(root->right,M,V);
    
    string S = to_string(root->data)+"$"+ls+"$"+rs;
    
    if(M[S]==1)
        V.push_back(root);
    
    M[S]++;
    return S;
}
vector<Node*> printAllDups(Node* root)
{
    vector<Node*> V;
    unordered_map<string,int> M;
    
    solve(root,M,V);
    
    return V;
    // Code here
}