#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void postorder(Node *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

vector<int> postorderTraversal(Node *root)
{
    vector<int> postOrder;
    if (!root)
        return postOrder;

    stack<Node *> stack;

    stack.push(root);

    while (!stack.empty())
    {
        Node *curr = stack.top();
        stack.pop();

        postOrder.insert(postOrder.begin(), curr->data);

        if (curr->left)
            stack.push(curr->left);
        if (curr->right)
            stack.push(curr->right);
    }
    return postOrder;
}

/*
** 2 stacks
1. pop from in stack -> cur put to out stack
2. push cur->left to in stack
3. push cur->right to in stack

4. empty the out stack to res vector
*/

void postorderIterative(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<Node *> s;
    s.push(root);

    // create another stack to store postorder traversal
    stack<int> out;

    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node *curr = s.top();
        s.pop();
        out.push(curr->data);

        if (curr->left)
        {
            s.push(curr->left);
        }

        if (curr->right)
        {
            s.push(curr->right);
        }
    }

    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}

vector<int> postorderTraversal(Node *root)
{
    vector<int> postOrder;
    if (root == NULL)
        return postOrder;

    stack<Node *> stack;

    stack.push(root);

    while (!stack.empty())
    {
        Node *curr = stack.top();
        stack.pop();

        postOrder.insert(postOrder.begin(), curr->data);

        if (curr->left != NULL)
            stack.push(curr->left);

        if (curr->right != NULL)
            stack.push(curr->right);
    }
    return postOrder;
}