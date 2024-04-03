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

void parentBFS(Node* root, unordered_map<int,int> &M)
{
    M[root->data] = -1;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node* cur = Q.front();Q.pop();

        if(cur->left)
        {
            M[cur->left->data] = cur->data;
            Q.push(cur->left);
        }
        if(cur->right)
        {
            M[cur->right->data] = cur->data;
            Q.push(cur->right);
        }
    }
}

int KthAncestor(Node* root,int K,int node)
{
    unordered_map<int,int> M;
    parentBFS(root,M);

    int count = 0;
    while(M.find(node)!=M.end())
    {
        node = M[node];
        count++;

        if(count==K) return node;

    }
    return -1;
}
