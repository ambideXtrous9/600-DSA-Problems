#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef pair<int,Node*> ip; 

Node *mergeKLists(Node *arr[], int K)
{
    Node *head = NULL;
    priority_queue<ip, vector<ip>, greater<ip>> pq;

    for (int i = 0; i < K; i++)
    {
        pq.push({arr[i]->data, arr[i]});
    }
    Node *curr = NULL;

    while (!pq.empty())
    {
        Node *temp = pq.top().second;
        pq.pop();

        if (temp->next != NULL)
            pq.push({temp->next->data, temp->next});

        if (head == NULL)
        {
            temp->next = head;
            head = temp;
            curr = head;
        }
        else
        {
            Node *x = curr->next;
            temp->next = x;
            curr->next = temp;
            curr = curr->next;
        }
    }
    return head;
}