#include <bits/stdc++.h>

using namespace std;

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

int getNthFromLast(Node *head, int n)
{
    Node *curr = head;
    Node *save = head;
    while (curr)
    {
        if (n)
        {
            curr = curr->next;
            n--;
        }
        else
        {
            save = save->next;
            curr = curr->next;
        }
    }
    if (n)
        return -1;
    return save->data;
}