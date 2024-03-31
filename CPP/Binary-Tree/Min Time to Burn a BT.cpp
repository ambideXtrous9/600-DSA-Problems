#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
1. first find parent of every node using BFS and target node also
2. then use BFS to burn for left,right, and parent
3. (keep flag to track if any node is burnt at that time instant) -> then only increment the level
*/


int LetsBurn(Node *root, unordered_map<Node *, Node *> &M)
{
    queue<Node *> Q;

    unordered_map<Node *, int> vis;

    Q.push(root);

    int level = 0;

    while (!Q.empty())
    {
        int n = Q.size();

        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            auto node = Q.front();
            Q.pop();

            if (node->left && !vis[node->left]) // left child
            {
                flag = 1;
                vis[node->left] = 1;

                Q.push(node->left);
            }
            if (node->right && !vis[node->right]) // right child
            {
                flag = 1;
                vis[node->right] = 1;

                Q.push(node->right);
            }

            if (M[node] && !vis[M[node]]) // its parent
            {
                flag = 1;
                vis[M[node]] = 1;

                Q.push(M[node]);
            }
        }

        if (flag)
            level++;
    }

    return level;
}

Node *ParentFinder(Node *root, int target, unordered_map<Node *, Node *> &M)
{
    queue<Node *> Q;

    Q.push(root);

    Node *head = NULL;

    while (!Q.empty())
    {
        auto node = Q.front();
        Q.pop();

        if (node->data == target)
            head = node;

        if (node->left)
        {
            M[node->left] = node;
            Q.push(node->left);
        }
        if (node->right)
        {
            M[node->right] = node;
            Q.push(node->right);
        }
    }

    return head; // returns the start node 
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> M;
    Node *tar = ParentFinder(root, target, M);

    if (!tar)
        return 0;

    return LetsBurn(tar, M);
}