#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
1. Use Levelwise BFS or Levelorder 
2. use flag toggle for reverse order 
3. and for storing reverse order use STACK and dump it to res array.
*/
vector<int> zigZagTraversal(Node *root)
{
    vector<int> V;
    if (!root)
        return V;
    queue<Node *> Q;
    Q.push(root);
    int flag = 0;

    while (!Q.empty())
    {
        int n = Q.size();
        if (flag == 0)
        {
            for (int i = 0; i < n; i++)
            {
                Node *front = Q.front();
                Q.pop();
                V.push_back(front->data);
                if (front->left)
                    Q.push(front->left);
                if (front->right)
                    Q.push(front->right);
            }
            flag = 1;
        }
        else if (flag == 1)
        {
            stack<Node *> S;
            
            for (int i = 0; i < n; i++)
            {
                Node *front = Q.front();
                S.push(front);
                Q.pop();

                if (front->left)
                    Q.push(front->left);
                if (front->right)
                    Q.push(front->right);
            }
            while (!S.empty())
            {

                V.push_back(S.top()->data);
                S.pop();
            }
            flag = 0;
        }
    }
    return V;
}