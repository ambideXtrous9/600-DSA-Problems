// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head)
{
    Node *root = new Node(-1);
    Node *temp = root;
    Node *cur = head;
    while (cur)
    {
        Node *t = new Node(cur->data);
        temp->next = t;
        temp = t;
        cur = cur->next;
    }
    cur = head;
    Node *cur1 = head;
    root = root->next;

    Node *cur2 = root;
    Node *cur3 = root;

    while (cur3)
    {
        if (cur->arb)
        {
            int n = 0;

            while (cur1 != cur->arb)
            {
                cur1 = cur1->next;
                n++;
            }
            while (n--)
            {
                cur2 = cur2->next;
            }
            cur3->arb = cur2;
            cur2 = root;
            cur1 = head;
        }
        cur3 = cur3->next;
        cur = cur->next;
    }

    return root;
}

Node *copyList(Node *head)
{
    Node *root = new Node(-1);
    Node *temp = root;
    Node *cur = head;
    unordered_map<Node *, Node *> M;
    while (cur)
    {
        Node *t = new Node(cur->data);
        M[cur] = t;
        temp->next = t;
        temp = t;
        cur = cur->next;
    }
    cur = head;
    root = root->next;
    Node *cur2 = root;
    while (cur2)
    {
        cur2->arb = M[cur->arb];
        cur2 = cur2->next;
        cur = cur->next;
    }
    return root;
}
