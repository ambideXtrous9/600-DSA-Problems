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

vector<vector<int>> ans;

void solve(Node *root, vector<int> v, int k, int &sum)
{
    if (!root)
        return;
    
    k += root->data;
    
    v.push_back(root->data);
    
    if (k == sum)
    {
        ans.push_back(v);
        return;
    }
    
    solve(root->left, v, k, sum);
    solve(root->right, v, k, sum);
}
vector<vector<int>> printPaths(Node *root, int sum)
{
    ans.clear();
    vector<int> v;
    if (!root)
        return ans;
    int k = 0;
    solve(root, v, k, sum);
    return ans;
}