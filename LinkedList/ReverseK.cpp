#include <bits/stdc++.h>

using namespace std;

struct node *reverse(struct node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    // reverse  first k nodes
    int count = 0;
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverse(next, k);
    }

    return prev;
}