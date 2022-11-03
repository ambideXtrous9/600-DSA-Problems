#include <bits/stdc++.h>

using namespace std;

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

Node *rotateDLL(Node *start, int p)
{
    if (p == 0)
        return start;
    int count = 1;

    Node *cur = start;

    while (cur && count < p)
    {
        cur = cur->next;
        count++;
    }

    Node *nth = cur;

    while (cur->next)
    {
        cur = cur->next;
    }

    cur->next = start;
    start->prev = cur;

    start = nth->next;
    nth->next = NULL;
    start->prev = NULL;

    return start;
}