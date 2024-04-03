#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int solve(Node *root, int &cam)
{
    if (!root)
        return 1; // no node so take it as already covered.

    int l = solve(root->left, cam);
    int r = solve(root->right, cam);

    if (l == -1 || r == -1) // -1 rep not covered (child or children not covered)
    {
        cam++;    // install the cam at the node
        return 0; //  and 0 rep node is installed in that node.
    }
    if (l == 0 || r == 0)
        return 1; // if children has cam then obviously parent is covered

    return -1; // otherwise not covered
}

int minCameraCover(Node *root)
{
    int cam = 0;

    if (solve(root, cam) == -1)
        cam++; // if root not covered

    return cam;
}