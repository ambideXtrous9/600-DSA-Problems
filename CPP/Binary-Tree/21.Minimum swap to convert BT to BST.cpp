#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void inorder(int a[], vector<int> &v,int n, int index)
{
    if(index >= n)
        return;
    
    inorder(a, v, n, 2 * index + 1);
     
    v.push_back(a[index]);
    
    inorder(a, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &nums)
{

    int n = nums.size();
    vector<pair<int, int>> V(n);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        V[i] = {nums[i], i};
    }

    sort(V.begin(), V.end());

    for (int i = 0; i < n; i++)
    {
        if (i != V[i].second)
        {
            count++;
            swap(V[i], V[V[i].second]);
            i--;
        }
    }

    return count;
}

int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}