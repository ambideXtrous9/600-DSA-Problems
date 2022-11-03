#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Map<Node*, y_coord> + Normal BFS or Levelorder

vector<int> topView(Node *root)
{
    vector<int> V;
    if (!root)
        return V;
    
    queue<pair<Node *, int>> Q;
    map<int, int> M;
    
    Q.push({root, 0});

    while (!Q.empty())
    {
        auto it = Q.front();
        Q.pop();
        
        auto curr = it.first;
        int y = it.second;
        
        if (M.find(y) == M.end())
        {
            M[y] = curr->data;
        }
        
        if (curr->left)
            Q.push({curr->left, y - 1});
        
        if (curr->right)
            Q.push({curr->right, y + 1});
    }
    for (auto it : M)
    {
        V.push_back(it.second);
    }
    return V;

    // Your code here
}