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

vector<int> FindNode(Node *root, unordered_map<Node *, Node *> &M, int k)
{
    unordered_map<Node *, int> vis;

    queue<Node *> Q;

    Q.push(root);

    vis[root] = 1;

    vector<int> V;

    int level = 0;

    while (!Q.empty())
    {
        int n = Q.size();

        for (int i = 0; i < n; i++)
        {
            auto node = Q.front();
            Q.pop();

            if (level == k)
                V.push_back(node->data);

            if (node->left && !vis[node->left])
            {

                vis[node->left] = 1;

                Q.push(node->left);
            }
            if (node->right && !vis[node->right])
            {

                vis[node->right] = 1;

                Q.push(node->right);
            }

            if (M[node] && !vis[M[node]])
            {

                vis[M[node]] = 1;

                Q.push(M[node]);
            }
        }

        level++;
    }

    return V;
}

Node *ParentFinder(Node *root, unordered_map<Node *, Node *> &M, int target)
{
    queue<Node *> Q;

    Q.push(root);

    while (!Q.empty())
    {
        auto node = Q.front();
        Q.pop();

        if (node->data == target)
            root = node;

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

    return root;
}

vector<int> KDistanceNodes(Node *root, int target, int k)
{
    unordered_map<Node *, Node *> M;

    root = ParentFinder(root, M, target);

    vector<int> v = FindNode(root, M, k);

    sort(v.begin(), v.end());

    return v;
    // return the sorted vector of all nodes at k dist
}