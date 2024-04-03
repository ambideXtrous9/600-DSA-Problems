#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

//TC-> O(NlogN), SC-> O(N)+O(N) [1 for vector, 1 for recursion space]

vector<int> v;
int i = 0;

void sol1(Node *n)
{
    if (!n)
        return;
    sol1(n->left);
    v.push_back(n->val);
    sol1(n->right);
}

void sol2(Node *n)
{
    if (!n)
        return;
    sol2(n->left);
    n->val = v[i++];
    sol2(n->right);
}

void recoverTree(Node *root)
{
    sol1(root);
    sort(v.begin(), v.end());
    sol2(root);
}

// TC-> O(N), SC->O(N) [for recursion space]

void inorder(Node *root,Node* &first, Node* &last, Node* &prev)
{
    if (root == NULL)
        return;
    inorder(root->left,first,last,prev);
    if (prev != NULL && (root->val < prev->val))
    {
        if (first == NULL)
        {
            first = prev;
            last = root;
        }
        else
            last = root;
    }
    
    prev = root;

    inorder(root->right,first,last,prev);
}
void recoverTree(Node *root)
{

    Node* first = NULL; Node* last = NULL ; Node* prev = NULL;
    inorder(root,first,last,prev);
    swap(first->val, last->val);
}