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

int height(Node *root)
{
    if (!root)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r);
}

bool sameLevel(Node *root, int h)
{
    if (!root)
        return true;

    if (h == 1 && (!root->left && !root->right))
        return true;

    if (h != 1 && (!root->left && !root->right))
        return false;

    return sameLevel(root->left, h - 1) && sameLevel(root->right, h - 1);
}
bool check(Node *root)
{
    int h = height(root);

    return sameLevel(root, h);
    // Your code here
}

void fill(set<int> &v, Node *root, int level)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        v.insert(level);
    }
    fill(v, root->left, level + 1);
    fill(v, root->right, level + 1);
}

bool check(Node *root)
{
    // Your code here
    set<int> s;
    fill(s, root, 0);
    return s.size() == 1;
}