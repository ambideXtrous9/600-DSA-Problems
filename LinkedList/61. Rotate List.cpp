#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{

    if (!head || !head->next || k == 0)
        return head;

    ListNode *cur = head;
    ListNode *prev = NULL;

    int n = 0;

    while (cur)
    {
        prev = cur;
        cur = cur->next;
        n++;
    }

    prev->next = head;

    k = n - k % n;

    while (k)
    {
        prev = prev->next;
        k--;
    }

    head = prev->next;
    prev->next = NULL;

    return head;
}