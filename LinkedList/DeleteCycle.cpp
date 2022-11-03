#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void removeLoop(Node *head)
{
    if (!head or !head->next)
        return;

    // check for cycle
    Node *slow = head, *fast = head, *prev = NULL;

    while (fast and fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break; // if cycle found
    }

    if (slow != fast)
        return; // no cycle --> just return

    fast = head;

    while (slow != fast)
    {
        prev = slow; 
        slow = slow->next; 
        fast = fast->next;
    }
        

    prev->next = NULL;
}