#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

vector<int> levelOrder(Node *node)
{
    vector<int> V;
    queue<Node *> Q;
    if (node == NULL)
        return V;
    Q.push(node);

    while (!Q.empty())
    {
        int n = Q.size();
        for (int i = 0; i < n; i++)
        {
            Node *top = Q.front();
            V.push_back(top->data);
            Q.pop();
            
            if (top->left)
                Q.push(top->left);
            
            if (top->right)
                Q.push(top->right);
        }
    }
    return V;
    // Your code here
}