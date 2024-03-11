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

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> V;
    stack<int> S;
    queue<Node *> Q;
    if (root == NULL)
        return V;
    Q.push(root);

    while (!Q.empty())
    {
        int n = Q.size();
        for (int i = 0; i < n; i++)
        {
            Node *front = Q.front();
            Q.pop();
            S.push(front->data);
            if (front->right)
                Q.push(front->right);
            if (front->left)
                Q.push(front->left);
        }
    }
    while (!S.empty())
    {
        V.push_back(S.top());
        S.pop();
    }
    return V;
    // code here
}