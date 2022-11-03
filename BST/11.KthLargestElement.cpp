#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


// for Kth Largest do reverse inorder -> right root left

void inorder(Node *root, int &k, int &ans)
{
    if (root == NULL)
        return;

    inorder(root->right, k, ans);

    k--;

    if (k == 0)
    {
        ans = root->data;

        return;
    }

    inorder(root->left, k, ans);
}

int kthLargest(Node *root, int k)
{
    int ans = 0;

    inorder(root, k, ans);

    return ans;
}

void kthLargestNode(Node *root, int K, priority_queue<int, vector<int>, greater<int>> &MH)
{
    if (!root)
        return;

    MH.push(root->data);
    if (MH.size() > K)
        MH.pop();

    kthLargestNode(root->left, K, MH);
    kthLargestNode(root->right, K, MH);
}

int kthLargest(Node *root, int K)
{
    priority_queue<int, vector<int>, greater<int>> MH;
    kthLargestNode(root, K, MH);

    return MH.top();
}