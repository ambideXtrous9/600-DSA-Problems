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

int mod = 1e9 + 7;

void number(Node *L, int &num)
{
    if (!L)
        return;

    num = (10 * num + L->data) % mod;

    number(L->next, num);
}

long long multiplyTwoLists(Node *l1, Node *l2)
{

    long long num1 = 0;
    long long num2 = 0;

    while (l1)
    {
        num1 = (10 * num1 + l1->data) % mod;
        l1 = l1->next;
    }

    while (l2)
    {
        num2 = (10 * num2 + l2->data) % mod;
        l2 = l2->next;
    }

    return (num1 * num2) % mod;
}