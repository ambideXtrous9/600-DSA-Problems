#include <stdio.h>
#include <stdlib.h>

/* structure for a Node */
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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if (!head || !head->next)
        return;

    Node *fast = head->next;
    Node *slow = head;
    Node *prev = NULL;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next->next;
    }
    if (fast != head)
        fast->next = slow->next;
    else
        prev->next->next = slow->next;
    *head2_ref = slow->next;
    *head1_ref = head;
    slow->next = head;
}