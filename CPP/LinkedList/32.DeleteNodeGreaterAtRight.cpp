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

Node *compute(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;

    while (cur)
    {
        if (cur->next && cur->data < cur->next->data)
        {
            if (cur == head)
            {
                head = cur->next;
                cur->next = NULL;
                free(cur);
                cur = head;
                continue;
            }
            else
            {
                prev->next = cur->next;
                cur->next = NULL;
                free(cur);
                cur = head;
                prev = NULL;
                continue;
            }
        }
        prev = cur;
        cur = cur->next;
    }

    return head;
}

Node *compute(Node *head)
{
    if (!head || !head->next) return head;
    
    Node *root = compute(head->next);
    
    if (head->data < root->data)
    {
        return root;
    }
    else
    {
        head->next = root;
        return head;
    }
}

Node *reverse(Node *head)
{
    Node *current = head;
    Node *previous = NULL;
    Node *temp = NULL;
    while (current != NULL)
    {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    return previous;
}
Node *compute(Node *head)
{
    // your code here
    head = reverse(head);
    int max_so_far_RHS = head->data;
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data < max_so_far_RHS)
        {
            temp->next = temp->next->next;
        }
        else
        {
            max_so_far_RHS = temp->next->data;
            temp = temp->next;
        }
    }
    head = reverse(head);
    return head;
}