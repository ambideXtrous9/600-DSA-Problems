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

int sum(Node *root, int &res)
{
    if (!root)
        return 0;

    int l = sum(root->left, res);
    int r = sum(root->right, res);

    int ans_path = root->data + l + r;

    int not_ans_path = root->data + max(l, r);

    // now could be potential ans when its both left and right exist

    if (root->left && root->right)
    {
        res = max(res, ans_path);

        return not_ans_path; // when both exist, take the max of them for future
    }

    // when either of the child is missing
    // return not_ans_path won't work as null returns 0 a
    // and on the other child it may be -ve val, i that case it
    // max(-ve,0) = 0 -> which does not exist ignoring the child
    // having -ve val. so we need to write explicitly

    if (root->left)
        return root->data + l;

    else
        return root->data + r;
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;

    int ans = sum(root, res);

    return res;

    //----------------- GFG ----------------------------

    if (root->left && root->right)
        return res;

    return max(res, ans);
    // code here
}