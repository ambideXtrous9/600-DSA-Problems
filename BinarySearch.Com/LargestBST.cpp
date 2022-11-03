#include <bits/stdc++.h>

using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};



// O(N^2)

int count(Tree *root)
{
    if (!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

bool isValidBST(Tree *root, Tree *l = NULL, Tree *r = NULL)
{
    if (root == NULL)
        return true;
    if (l != NULL && l->val >= root->val)
        return false;
    if (r != NULL && r->val <= root->val)
        return false;

    return isValidBST(root->left, l, root) && isValidBST(root->right, root, r);
}

void inorder(Tree* root,int &k,Tree* &head)
{
    if(!root) return;

    if(isValidBST(root))
    {
        int p = count(root);
        if(p>k)
        {
            k = p;
            head = root;
        }
    }

    inorder(root->left,k,head);
    inorder(root->right,k,head);
}

Tree* solve(Tree* root) 
{
    int k = INT_MIN;
    Tree* head = NULL;
    inorder(root,k,head);

    return head;
}

// O(N)

vector<int> LargestBST(Tree *root, int &ans)
{
    if (!root)
        return {INT_MIN, INT_MAX, 1, 0};
    vector<int> L = LargestBST(root->left, ans);
    vector<int> R = LargestBST(root->right, ans);

    vector<int> cur;
    
    cur.push_back(max(root->val, R[0]));
    cur.push_back(min(root->val, L[1]));
    
    if (R[2] && L[2] && root->val > L[0] && root->val < R[1])
        cur.push_back(1);
    else
        cur.push_back(0);
    cur.push_back(1 + L[3] + R[3]);
    
    if (cur[2])
        ans = max(ans, cur[3]);
    
    return cur;
}

int largestBst(Tree *root)
{
    int ans = INT_MIN;
    vector<int> V = LargestBST(root, ans);
    return ans;
    // Your code here
}