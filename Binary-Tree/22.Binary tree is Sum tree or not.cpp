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

int solve(Node *root,bool &ans)
{
    if (!root)
        return 0;

    int x = root->data;

    int l = solve(root->left,ans);
    int r = solve(root->right,ans);

    ans = ans && root->data == l + r;

    return l + r + x;
}
bool toSumTree(Node *node)
{
    bool ans = true;
    int x = solve(node,ans);

    return ans;
}