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

Node *deleteNode(Node *head, int x)
{
    Node *cur = head;
    Node *prev = NULL;

    while (cur && x != 1)
    {
        prev = cur;
        cur = cur->next;
        x--;
    }

    if (cur == head)
        return head = cur->next;

    else
        prev->next = cur->next;

    return head;
}