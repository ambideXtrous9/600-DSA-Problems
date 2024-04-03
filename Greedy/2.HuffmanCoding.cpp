#include <bits/stdc++.h>
using namespace std;

struct HuffmanNode
{
    char data;
    int freq;
    struct HuffmanNode *left, *right;

    HuffmanNode(char c, int n)
    {
        data = c;
        freq = n;
        left = right = NULL;
    }
};

struct comp
{

    bool operator()(HuffmanNode *l, HuffmanNode *r)
    {
        return (l->freq > r->freq);
    }
};

void getCode(HuffmanNode *root, string S)
{
    if (!root)
        return;

    if (root->data != '$')
    {
        cout << root->data << " : " << S << endl;
    }

    getCode(root->left, S + "0");
    getCode(root->right, S + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, comp> MH;

    for (int i = 0; i < size; i++)
    {
        MH.push(new HuffmanNode(data[i], freq[i]));
    }

    while (MH.size() != 1)
    {

        auto t1 = MH.top();
        MH.pop();

        auto t2 = MH.top();
        MH.pop();

        auto N = new HuffmanNode('$', t1->freq + t2->freq);

        N->left = t1;
        N->right = t2;

        MH.push(N);
    }

    auto N = MH.top();
    MH.pop();

    getCode(N, "");
}

int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {10, 5, 2, 14, 15};

    int size = 5;
    HuffmanCodes(arr, freq, size);

    return 0;
}