#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

/*
1. keep on pushing left into stack until NULL is hit
2. pop one from stack and store to res vector.
3. move to right of the popped node.
*/

void inorder(Node *root)
{
    if (!root)
        return;

    stack<Node *> S;

    Node *cur = root;

    while (!S.empty() || cur)
    {
        if (cur)
        {
            S.push(cur);
            cur = cur->left;
        }
        else
        {
            auto cur = S.top();
            S.pop();

            cout << cur->data << " ";

            cur = cur->right;
        }
    }
}
