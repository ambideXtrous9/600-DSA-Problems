#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeLists(Node *l1, Node *l2)
{
    Node *dummy = new Node(0);
    Node *ptr = dummy;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            ptr->bottom = l1;
            l1 = l1->bottom;
        }
        else
        {
            ptr->bottom = l2;
            l2 = l2->bottom;
        }
        ptr = ptr->bottom;
    }
    if (l1)
    {
        ptr->bottom = l1;
    }
    else if (l2)
    {
        ptr->bottom = l2;
    }

    return dummy->bottom;
}

Node *flatten(Node *root)
{
    if (root == nullptr || root->next == nullptr)
    {
        return root;
    }
    root->next = flatten(root->next); // recursive function
    return root = mergeLists(root, root->next);
}