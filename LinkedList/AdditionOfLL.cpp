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

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    stack<int> S1, S2;
    Node *cur1 = first;
    Node *cur2 = second;

    while (cur1 != NULL)
    {
        S1.push(cur1->data);
        cur1 = cur1->next;
    }
    while (cur2 != NULL)
    {
        S2.push(cur2->data);
        cur2 = cur2->next;
    }

    int carry = 0;
    Node *root = NULL;
    Node *cur = NULL;

    while (!S1.empty() && !S2.empty())
    {
        int t = S1.top() + S2.top() + carry;
        Node *temp = new Node(t % 10);
        carry = t / 10;

        temp->next = root;
        root = temp;

        S1.pop();
        S2.pop();
    }
    while (!S1.empty())
    {
        int t = S1.top() + carry;
        Node *temp = new Node(t % 10);
        carry = t / 10;

        temp->next = root;
        root = temp;

        S1.pop();
    }
    while (!S2.empty())
    {
        int t = S2.top() + carry;
        Node *temp = new Node(t % 10);
        carry = t / 10;

        temp->next = root;
        root = temp;

        S2.pop();
    }

    if (carry != 0)
    {
        Node *temp = new Node(carry);

        temp->next = root;
        root = temp;
    }

    return root;
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    /* reverse the rest list and put
      the first element at the end */
    Node *rest = reverse(head->next);
    head->next->next = head;

    /* tricky step -- see the diagram */
    head->next = NULL;

    /* fix the head pointer */
    return rest;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    Node *ans = NULL;
    first = reverse(first);
    second = reverse(second);
    int carry = 0;
    Node *cur = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int newval = 0;
        int sum = 0;
        if (first != NULL)
        {
            newval += first->data;
            first = first->next;
        }
        if (second != NULL)
        {
            newval += second->data;
            second = second->next;
        }
        newval += carry;
        sum = newval % 10;
        carry = newval / 10;

        Node *newnode = new Node(sum);

        if (!ans)
        {
            ans = newnode;
            cur = ans;
        }
        else
        {
            newnode->next = cur->next;
            cur->next = newnode;
            cur = newnode;
        }
    }
    if (carry != 0)
    {
        Node *newnode = new Node(carry);

        newnode->next = cur->next;
        cur->next = newnode;
        cur = newnode;
    }
    return reverse(ans);
}