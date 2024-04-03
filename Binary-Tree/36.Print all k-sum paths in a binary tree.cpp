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

/*
Here each node can be treated as root, hence the path can start and end at any node.
The basic idea to solve the problem is to do a preorder traversal of the given tree.
We also need a container (vector) to keep track of the path that led to that node.
At each node we check if there are any path that sums to k, if any we print the path and
proceed recursively to print each path.
*/

void printVector(const vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void printKPathUtil(Node *root, vector<int> &path, int k)
{
    // empty node
    if (!root)
        return;

    path.push_back(root->data);

    printKPathUtil(root->left, path, k);

    printKPathUtil(root->right, path, k);

    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];

        if (f == k)
            printVector(path, j);
    }
    path.pop_back();
}