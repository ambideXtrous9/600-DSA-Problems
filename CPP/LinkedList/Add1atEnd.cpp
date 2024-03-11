#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void rev(Node *cur, int &carry, int &one)
{
    if (!cur)
        return;

    rev(cur->next, carry, one);

    int temp = cur->data + one + carry;
    cur->data = temp % 10;
    carry = temp / 10;
    one = 0;
}

Node *addOne(Node *head)
{
    int carry = 0;
    int one = 1;

    rev(head, carry, one);

    if (carry == 1)
    {
        Node *temp = new Node(1);
        temp->next = head;
        head = temp;
    }

    return head;
}