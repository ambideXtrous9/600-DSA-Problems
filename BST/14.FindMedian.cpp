#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

float MorrisOrderTraversalMedian(Node *root, int n)
{
    Node *cur = root;
    Node *pre = NULL;

    int count = 0;

    int m1, m2;

    while (cur)
    {
        if (!cur->left)
        {
            if (count == n / 2)
            {
                m2 = cur->data;
            }
            if (count == n / 2 - 1)
            {
                m1 = cur->data;
            }
            // count current node

            count++;
            // check if current node is the median

            // Update prev for even no. of nodes
            pre = cur;
            cur = cur->right;
        }
        else
        {
            Node *prev = cur->left;

            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur; // making the thread
                cur = cur->left;   // moving left
            }
            else
            {
                pre = prev;

                if (count == n / 2)
                {
                    m2 = cur->data;
                }
                if (count == n / 2 - 1)
                {
                    m1 = cur->data;
                }
                // count current node

                count++;

                pre = cur;
                prev->right = NULL; // cutting the thread
                cur = cur->right;   // moving right
            }
        }
    }
    if (n % 2)
    {
        return m2;
    }
    else
    {
        return (m1 + m2) / ((float)2);
    }
}

int MorrisOrderTraversalCount(Node *root)
{
    int count = 0;
    Node *cur = root;

    while (cur)
    {
        if (!cur->left)
        {
            count++;
            cur = cur->right;
        }
        else
        {
            Node *prev = cur->left;

            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur; // making the thread
                cur = cur->left;   // moving left
            }
            else
            {
                count++;
                prev->right = NULL; // cutting the thread
                cur = cur->right;   // moving right
            }
        }
    }

    return count;
}

float findMedian(struct Node *root)
{
    int count = MorrisOrderTraversalCount(root);

    float med = MorrisOrderTraversalMedian(root, count);

    return med;
}