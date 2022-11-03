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

vector<int> LargestBST(Node *root, int &ans)
{
    if (!root)
        return {INT_MIN, INT_MAX, 1, 0};
    
    vector<int> L = LargestBST(root->left, ans);
    vector<int> R = LargestBST(root->right, ans);

    vector<int> cur;
    
    cur.push_back(max(root->data, R[0]));
    cur.push_back(min(root->data, L[1]));
    
    if (R[2] && L[2] && root->data > L[0] && root->data < R[1])
        cur.push_back(1);
    else
        cur.push_back(0);
    
    cur.push_back(1 + L[3] + R[3]);
    
    if (cur[2])
        ans = max(ans, cur[3]);
    
    return cur;
}

int largestBst(Node *root)
{
    int ans = INT_MIN;
    vector<int> V = LargestBST(root, ans);
    return ans;
    // Your code here
}