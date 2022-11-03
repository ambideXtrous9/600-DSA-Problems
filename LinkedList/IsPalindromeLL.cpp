
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

bool compare(Node *&start, Node *end)
{
    if (end == NULL)
        return true;
    if (compare(start, end->next) == false || start->data != end->data)
        return false;
    start = start->next;
    return true;
}
bool isPalindrome(Node *head)
{
    return compare(head, head);
}

bool isPalindrome(Node *head)
{

    // Temp pointer
    Node *slow = head;
    Node *fast = head;
    // Declare a stack
    stack<int> s;

    // Push all elements of the list
    // to the stack
    while (fast && fast->next)
    {
        s.push(slow->data);
        // Move ahead
        slow = slow->next;
        fast = fast->next->next;
    }

    

    if(fast) 
    {
        slow = slow->next;
    }
    
    while(slow)
    {

        if(slow->data != s.top())
        {
            return false;
        }
        else
        {
            slow = slow->next;
            s.pop();
        }
    }
    return true;
}