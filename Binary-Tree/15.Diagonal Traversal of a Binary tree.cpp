#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
1. store left child node to Q, to start every diagonal traversal

2. and from node keep on traversing to right to get the diagonal

*/

/*
1. Push the root node onto a queue.
2. Take the next node from the front of the queue.
3. Add this node's data to the end of the answer vector.
4. Push the node's left child onto the back of the queue.
5. Move on to the node's right child.
6. Repeat steps 3 through 5 until reaching a null node, processing all the node's right descendants.
7. Take the next node off the queue and repeat: Go to step 2 if the queue is nonempty, otherwise we're done.
*/

vector<int> diagonal(Node *root)
{
    vector<int> V;

    if(!root) return V;

    queue<Node*> Q;

    Q.push(root);

    while (!Q.empty())
    {
        auto cur = Q.front(); 
        
        Q.pop();

        while(cur)
        {
            V.push_back(cur->data);

            if(cur->left) Q.push(cur->left);

            cur = cur->right;
        }
    }

    return V;
    
}
