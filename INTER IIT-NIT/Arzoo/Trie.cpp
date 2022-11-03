#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag;
    int c = 0;
    
    bool containskey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *getref(char ch)
    {
        return links[ch - 'a'];
    }
    bool getend()
    {
        return flag;
    }
    void setend()
    {
        flag = true;
    }
};


class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root; // temp node
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containskey(word[i])))
                node->put(word[i], new Node());

            node = node->getref(word[i]);
            node->c++;
        }
        node->setend();
    }

    int search(string pre)
    {
        Node *node = root; // temp node
        for (int i = 0; i < pre.size(); i++)
        {
            if (!node->containskey(pre[i]))
                return 0;
            node = node->getref(pre[i]);
        }
        return node->c;
    }
};


int main()
{
    int N = 5;
    vector<string> words = {"apk", "app", "apple", "arp", "array"};
    
    string pre = "ap";
    Trie T;
    
    for (int i = 0; i < N; i++)
    {
        T.insert(words[i]);
    }
    
    cout << T.search(pre);
}