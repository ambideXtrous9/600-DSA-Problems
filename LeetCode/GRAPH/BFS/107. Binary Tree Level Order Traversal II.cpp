#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> V;

    if(!root) return V;

    stack<vector<int>> S;

    queue<TreeNode*> Q;

    Q.push(root);

    while (!Q.empty())
    {
        int n = Q.size();

        vector<int> arr;

        for(int i= 0;i<n;i++)
        {
            TreeNode* node = Q.front();
            Q.pop();

            arr.push_back(node->val);

            if(node->left) Q.push(node->left);
            if(node->right) Q.push(node->right);
        }

        S.push(arr);
    }

    while (!S.empty())
    {
        V.push_back(S.top());
        S.pop();
        /* code */
    }

    return V; 
}