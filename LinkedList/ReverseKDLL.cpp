#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLLInGroups(Node *head, int k)
{
    if (!head || !head->next)
        return head;
    Node *current = head;
    Node *next = NULL;
    Node *back = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = back;
        current->prev = next;
        back = current;
        current = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverseDLLInGroups(next, k);
    }

    return back;
}
