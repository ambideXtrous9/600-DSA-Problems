#include <bits/stdc++.h>

using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};

class BSTIterator
{
private:
    stack<Tree *> S;

public:
    BSTIterator(Tree *root)
    {
        find_left(root);
    }

    void find_left(Tree *root)
    {
        Tree *p = root;
        while (p != NULL)
        {
            S.push(p);
            p = p->left;
        }
    }

    int next()
    {
        Tree *top = S.top();
        S.pop();
        if (top->right != NULL)
            find_left(top->right);

        return top->val;
    }

    bool hasnext()
    {
        if (S.empty())
            return false;
        return true;
    }
};