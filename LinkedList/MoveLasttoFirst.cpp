#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
 

void moveToFront(Node *head)
{
    /* If linked list is empty, or
    it contains only one node,
    then nothing needs to be done,
    simply return */
    if (head == NULL || head->next == NULL) return;
 
    /* Initialize second last
    and last pointers */
    Node *secLast = NULL;
    Node *last = head;
 
    /*After this loop secLast contains
    address of second last node and
    last contains address of last node in Linked List */
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
 
    /* Set the next of second last as NULL */
    secLast->next = NULL;
 
    /* Set next of last as head node */
    last->next = head;
 
    /* Change the head pointer
    to point to last node now */
    head = last;
}