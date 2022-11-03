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
        left = right = NULL;
    }
};

class LLNode
{
public:
    int val;
    LLNode *next;
};

Tree *solve(LLNode *node)
{
    if (!node)
        return NULL;

    int count = 1;

    LLNode *cur = node;

    Tree *root = new Tree(cur->val);

    Tree *head = root;

    LLNode *prev = cur;
    cur = cur->next;

    while (cur)
    {
        Tree *temp = new Tree(cur->val);
        if (prev->val > cur->val)
        {
            head->left = temp;
            head = head->left;
        }
        else
        {
            head->right = temp;
            head = head->right;
        }

        prev = cur;
        cur = cur->next;
    }

    return root;
}