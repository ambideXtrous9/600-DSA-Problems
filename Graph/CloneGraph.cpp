#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node *, Node *> mp;

void dfs(Node *node)
{
    Node *copy = new Node(node->val);
    mp[node] = copy;
    for (auto ng : node->neighbors)
    {
        if (mp.find(ng) != mp.end())
        {
            copy->neighbors.push_back(mp[ng]);
        }
        else
        {
            dfs(ng);
            copy->neighbors.push_back(mp[ng]);
        }
    }
}
Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return NULL;
    dfs(node);
    return mp[node];
}