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
    unordered_set<int> S;

    if (!head || !head->next)
        return head;

    Node *cur = head;

    Node *root = new Node(-1);
    Node *cur2 = root;

    while (cur)
    {
        if (S.find(cur->data) == S.end())
        {
            Node *temp = new Node(cur->data);

            cur2->next = temp;

            cur2 = cur2->next;

            S.insert(cur->data);
        }
        cur = cur->next;
    }
    return root->next;
}