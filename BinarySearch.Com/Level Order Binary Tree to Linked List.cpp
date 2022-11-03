#include <bits/stdc++.h>

using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
    Tree(int data)
    {
        val = data;
    }
};

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode(int data)
    {
        val = data;
    }
};

LLNode *solve(Tree *root)
{

    if (!root)
        return NULL;

    queue<Tree *> Q;

    Q.push(root);

    LLNode *head = new LLNode(-1);
    head->next = NULL;

    LLNode *cur = head;

    while (!Q.empty())
    {
        Tree *node = Q.front();
        Q.pop();

        LLNode *temp = new LLNode(node->val);

        temp->next = cur->next;

        cur->next = temp;

        cur = temp;

        if (node->left)
            Q.push(node->left);
        if (node->right)
            Q.push(node->right);
    }

    head = head->next;

    return head;
}