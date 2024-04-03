#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

/*
The idea is to start traversing the tree from the root node,
and keep printing the left child while exists and simultaneously,
push the right child of every node in an auxiliary stack.
Once we reach a null node, pop a right child from the auxiliary stack and
repeat the process while the auxiliary stack is not-empty.
*/

void preorderIterative(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;

    Node *curr = root;

    while (!st.empty() || curr)
    {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL)
        {
            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack if not empty
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

/*
** 1 stacks
1. pop from in stack -> cur put it to res vector.
2. push cur->right to in stack
3. push cur->left to in stack
*/

// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node *root)
{
    
    if (root == nullptr)
        return;

    stack<Node *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node *curr = stack.top();
        stack.pop();

        cout << curr->data << " ";

        // push the right child of the popped node into the stack
        if (curr->right)
        {
            stack.push(curr->right);
        }

        // push the left child of the popped node into the stack
        if (curr->left)
        {
            stack.push(curr->left);
        }
    }
}