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

Node *segregate(Node *head)
{

    int zero = 0, one = 0, two = 0;
    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == 0)
            zero++;
        else if (cur->data == 1)
            one++;
        else
            two++;
        cur = cur->next;
    }
    cur = head;
    while (cur != NULL)
    {
        if (zero > 0)
        {
            cur->data = 0;
            zero--;
        }
        else if (one > 0)
        {
            cur->data = 1;
            one--;
        }
        else
        {
            cur->data = 2;
        }
        cur = cur->next;
    }

    return head;
}