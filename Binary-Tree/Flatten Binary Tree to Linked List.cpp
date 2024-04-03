#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

/*
1. After storing its children in stack in reverse postorder manner : right then left
2. now put satck top on right of root and make left NULL in every itr.
*/

void flatten(node *root)
{
    if (root == NULL)
        return;

    stack<node *> st;

    st.push(root);

    while (!st.empty())
    {
        node *cur = st.top();

        st.pop();

        if (cur->right != NULL)
        {
            st.push(cur->right);
        }
        
        if (cur->left != NULL)
        {
            st.push(cur->left);
        }

        if (!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
}

class Solution
{
    node *prev = NULL;

public:
    void flatten(node *root)
    {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};