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


void inorder_successor(Node *root, Node *&succ, int key)
{
    while (root != NULL)
    {
        if (root->data <= key)
        {
            root = root->right;
        }
        else if (root->data > key)
        {
            succ = root;
            root = root->left;
        }
    }
}

struct Node *insertValue(struct Node *root, int value,Node* &succ) // BST construction
{

    if (root == NULL) // if root is null make the node as root
    {
        root = new Node(value);
        return root;
    }
    if (value < root->data) // if val is less then current node val then add it in LST
    {
        succ = root;
        root->left = insertValue(root->left, value,succ);
    }
    else // if val is > current node val then put it in RST
    {
        root->right = insertValue(root->right, value,succ);
    }

    return root; // atlast return the root;
}

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    Node* root = NULL;
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--)
    {
        Node* succ = NULL;

        root = insertValue(root,arr[i],succ);

        if(succ) ans[i] = succ->data;

        else ans[i] = -1;
    }

    return ans;
}

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    vector<int> V(n,-1);

    stack<int> S;

    for(int i = n-1;i>=0;i--)
    {
        while(!S.empty() && S.top() <= arr[i])
        {
            S.pop();
        }

        if(!S.empty()) V[i] = S.top();

        else V[i] = -1;

        S.push(arr[i]);
    }

    return V;
}

void solve(vector<int> &arr)
{
    set<int> s;
    vector<int> ans(arr.size());
    
    for (int i = arr.size() - 1; i >= 0; i--)
    {                                    // traversing the array backwards
        s.insert(arr[i]);                // inserting the element into set
        auto it = s.upper_bound(arr[i]); // finding upper bound
        if (it == s.end())
            arr[i] = -1; // if upper_bound does not exist then -1
        else
            arr[i] = *it; // if upper_bound exists, lets take it
    }
}