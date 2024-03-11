#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
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
// Function to find pair whose sum equal to given value x.
void pairSum(Node *head, int x)
{
    struct Node *first = head;
    struct Node *second = head;
    while (second->next != NULL) second = second->next;
 
    bool found = false;
    while (first != second && second->next != first)
    {
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", "<< second->data << ")" << endl;
 
            first = first->next;
 
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }

    if (found == false) cout << "No pair found";
}