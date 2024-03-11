#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node* StartLoopX(Node *head)
{
    if (!head or !head->next)
        return head;

    // check for cycle
    Node *slow = head, *fast = head;

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break; // if cycle found
    }

    if (slow != fast)
        return NULL; // no cycle --> just return

    fast = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}