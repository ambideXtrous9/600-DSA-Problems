#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Level Wise BFS or levelorder

vector<int> leftView(Node *root)
{
    vector<int> V;
    queue<Node *> Q;
    if (!root)
        return V;
    Q.push(root);
    while (!Q.empty())
    {
        int n = Q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = Q.front();
            Q.pop();
            if (i == 0)
            {
                V.push_back(temp->data);
            }
            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
        }
    }
    return V;
    // Your code here
}