#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(Node *head1, Node *head2)
{
    unordered_set<Node *> S;
    Node *cur = head1;
    while (cur)
    {
        S.insert(cur);
        cur = cur->next;
    }

    cur = head2;

    while (cur)
    {
        if (S.find(cur) != S.end())
            return cur->data;
        cur = cur->next;
    }
    return -1;

    // Your Code Here
}

int intersectPoint(Node *head1, Node *head2)
{
    {
        Node *p1 = head1, *p2 = head2;

        while (1)
        {
            if (p1 == p2)
                return p1->data;

            p1 = p1->next;
            p2 = p2->next;

            if (p1 == NULL and p2 == NULL)
                return -1;

            if (p1 == NULL)
                p1 = head2;

            if (p2 == NULL)
                p2 = head1;
        }
        return -1;
    }
}
