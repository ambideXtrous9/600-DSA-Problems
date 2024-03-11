#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int findIndex(string str, int start, int end)
{
    if (start > end)
        return -1;
    
    stack<char> stk;
   
    for (int i = start; i <= end; i++)
    {
        if (str[i] == '(')
        {
            stk.push('(');
        }
        else if (str[i] == ')')
        {
            if (stk.top() == '(')
            {
                stk.pop();
                if (stk.empty())
                {
                    return i;
                }
            }
        }
    }
    return -1;
}
Node *makeNode(string str, int start, int end)
{
    if (start > end)
        return NULL;
   
    int num = 0;
   
    while (start <= end and str[start] != '(' and str[start] != ')')
    {
        num = num * 10 + str[start++] - '0';
    }
    
    start--;
   
    Node *root = new Node(num);
   
    int index = -1;
   
    if (start + 1 < end and str[start + 1] == '(')
    {
        index = findIndex(str, start + 1, end);
    }
    if (index != -1)
    {
        root->left = makeNode(str, start + 2, index - 1);
        root->right = makeNode(str, index + 2, end - 1);
    }
   
    return root;
}
Node *treeFromString(string str)
{
    // code here
    int end = str.length() - 1;
    return makeNode(str, 0, end);
}