#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;

    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

struct ListNode *addTwoLists(struct ListNode *first, struct ListNode *second)
{
    stack<int> S1, S2;
    ListNode *cur1 = first;
    ListNode *cur2 = second;

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
    ListNode *root = NULL;
    ListNode *cur = NULL;

    while (!S1.empty() && !S2.empty())
    {
        int t = S1.top() + S2.top() + carry;
        ListNode *temp = new ListNode(t % 10);
        carry = t / 10;

        temp->next = root;
        root = temp;

        S1.pop();
        S2.pop();
    }
    while (!S1.empty())
    {
        int t = S1.top() + carry;
        ListNode *temp = new ListNode(t % 10);
        carry = t / 10;

        temp->next = root;
        root = temp;

        S1.pop();
    }
    while (!S2.empty())
    {
        int t = S2.top() + carry;
        ListNode *temp = new ListNode(t % 10);
        carry = t / 10;

        temp->next = root;
        root = temp;

        S2.pop();
    }

    if (carry != 0)
    {
        ListNode *temp = new ListNode(carry);

        temp->next = root;
        root = temp;
    }

    return root;
}

ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    /* reverse the rest list and put
      the first element at the end */
    ListNode *rest = reverse(head->next);
    head->next->next = head;

    /* tricky step -- see the diagram */
    head->next = NULL;

    /* fix the head pointer */
    return rest;
}

struct ListNode *addTwoLists(struct ListNode *first, struct ListNode *second)
{
    ListNode *ans = NULL;
    first = reverse(first);
    second = reverse(second);
    int carry = 0;
    ListNode *cur = NULL;
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

        ListNode *newListNode = new ListNode(sum);

        if (!ans)
        {
            ans = newListNode;
            cur = ans;
        }
        else
        {
            newListNode->next = cur->next;
            cur->next = newListNode;
            cur = newListNode;
        }
    }
    if (carry != 0)
    {
        ListNode *newListNode = new ListNode(carry);

        newListNode->next = cur->next;
        cur->next = newListNode;
        cur = newListNode;
    }
    return reverse(ans);
}