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

Node *findIntersection(Node *head1, Node *head2)
{
    Node *cur = NULL;
    Node *ans = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            Node *temp = new Node(temp1->data);
            if (ans == NULL)
            {
                temp->next = ans;
                ans = temp;
                cur = temp;
            }
            else
            {
                temp->next = cur->next;
                cur->next = temp;
                cur = temp;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->data > temp2->data)
        {
            temp2 = temp2->next;
        }
        else if (temp2->data > temp1->data)
        {
            temp1 = temp1->next;
        }
    }
    return ans;
}

Node *findIntersection(Node *head1, Node *head2)
{
    Node *ptr1 = head1, *ptr2 = head2;

    unordered_set<int> s;

    while (ptr2)
    {
        s.insert(ptr2->data);
        ptr2 = ptr2->next;
    }

    Node *ans = NULL;
    Node *cur = NULL;

    while (ptr1)
    {

        if (s.find(ptr1->data) != s.end())
        {
            Node *temp = new Node(ptr1->data);
            if (ans == NULL)
            {
                temp->next = ans;
                ans = temp;
                cur = temp;
            }
            else
            {
                temp->next = cur->next;
                cur->next = temp;
                cur = temp;
            }
            s.erase(ptr1->data);
        }
        ptr1 = ptr1->next;
    }
    return ans;
}