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

Node *divide(int N, Node *head)
{
    if (!head || !head->next)
        return head;

    Node *odd = new Node(-1);
    Node *odcur = odd;
    Node *even = new Node(-1);
    Node *evcur = even;

    Node *cur = head;

    while (cur)
    {
        if (cur->data % 2 == 0)
        {
            evcur->next = cur;
            evcur = evcur->next;
        }
        else
        {
            odcur->next = cur;
            odcur = odcur->next;
        }
        cur = cur->next;
    }

    odd = odd->next;
    even = even->next;

    if (!even)
        return odd;

    evcur->next = odd;
    odcur->next = NULL;

    return even;
}