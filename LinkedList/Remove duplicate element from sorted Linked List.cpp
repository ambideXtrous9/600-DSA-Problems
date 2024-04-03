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

Node *removeDuplicates(Node *head)
{
    if (!head || !head->next)
        return head;
    
    Node *cur = head;
    Node *prev = NULL;

    while (cur && cur->next)
    {
        Node *temp = cur->next;
        Node *temp2 = cur->next->next;

        if (cur->data == temp->data)
        {
            cur->next = temp2;
        }
        else
            cur = cur->next;
    }

    return head;
}