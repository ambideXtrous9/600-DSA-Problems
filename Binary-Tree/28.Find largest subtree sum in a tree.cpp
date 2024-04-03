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

int solve(Node *root,int &ans)
{
    if (!root)
        return 0;

    int l = solve(root->left,ans);
    int r = solve(root->right,ans);

    int sum = root->data + l + r;
    ans = max(ans,sum);
    
    return sum;
}
int toSumTree(Node *node)
{
    int ans = INT_MIN;
    int x = solve(node,ans);

    return ans;
}