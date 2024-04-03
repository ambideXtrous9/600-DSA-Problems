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

typedef pair<int,Node*> ip; 

// function to sort a k sorted doubly linked list
Node* sortAKSortedDLL(Node* head, int k)
{
    // if list is empty
    if (head == NULL)
        return head;
   
    priority_queue<ip, vector<ip>, greater<ip>> pq;

    Node* newHead = NULL; 
    Node* cur = NULL;
    Node* back = NULL;
 
    for (int i = 0; head != NULL && i <= k; i++) 
    {
        // push the node on to 'pq'
        pq.push({head->data,head});
        // move to the next node
        head = head->next;
    }
 
    // loop till there are elements in 'pq'
    while (!pq.empty()) {
 
        // place root or top of 'pq' at the end of the
        // result sorted list so far having the first node
        // pointed to by 'newHead'
        // and adjust the required links
        Node* temp = pq.top().second;
        pq.pop();

        if (newHead == NULL) 
        {
            temp->next = newHead;
            newHead = temp;
            newHead->prev = cur;
            cur = temp;
        }
 
        else 
        { 
            temp->next = cur->next;
            cur->next = temp;
            temp->prev = cur;
            cur = temp;
        }
 
        // if there are more nodes left in the input list
        if (head != NULL) 
        {
            // push the node on to 'pq'
            pq.push({head->data,head});
 
            // move to the next node
            head = head->next;
        }
    }
 
    // making 'next' of last node point to NULL
    cur->next = NULL;
    // new head of the required sorted DLL
    return newHead;
}