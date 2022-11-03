#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> V;

    Node *tail = head;
    Node *cur = head;

    while (tail->next)
    {
        tail = tail->next;
    }

    while (tail->data > cur->data)
    {
        int sum = tail->data + cur->data;

        if (sum == target)
        {
            V.push_back({cur->data, tail->data});
            tail = tail->prev;
            cur = cur->next;
        }
        else if (sum > target)
            tail = tail->prev;

        else
            cur = cur->next;
    }

    return V;
}