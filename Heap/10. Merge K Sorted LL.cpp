#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

typedef pair<int, Node *> ip;

// Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    priority_queue<ip, vector<ip>, greater<ip>> pq;

    for (int i = 0; i < K; i++)
    {
        pq.push({arr[i]->data, arr[i]});
    }
    Node *curr = NULL;

    Node *root = new Node(-1);
    Node *cur = root;

    while (!pq.empty())
    {
        Node *temp = pq.top().second;
        pq.pop();

        if (temp->next != NULL)
            pq.push({temp->next->data, temp->next});

        cur->next = temp;

        cur = cur->next;
    }
    return root->next;
}