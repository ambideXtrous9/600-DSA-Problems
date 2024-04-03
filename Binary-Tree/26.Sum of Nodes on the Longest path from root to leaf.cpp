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

void height(Node *root, int len, int &maxL, int &ans, int &res)
{
    if (!root)
        return;

    ans += root->data;

    height(root->left, len + 1, maxL, ans, res);
    height(root->right, len + 1, maxL, ans, res);

    if (len >= maxL)
    {
        maxL = len;
        res = max(res, ans);
    }

    ans -= root->data;
}

int sumOfLongRootToLeafPath(Node *root)
{
    int maxL = 0;
    int ans = 0;
    int res = INT_MIN;
    height(root, 0, maxL, ans, res);

    return res;
}