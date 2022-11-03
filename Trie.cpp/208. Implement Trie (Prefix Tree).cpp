#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag;
    int c;

    bool containsKey(char c)
    {
        return (links[c - 'a'] != NULL);
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }

    Node *getRef(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool getEnd()
    {
        return flag;
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
        Node *cur = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!cur->containsKey(word[i]))
            {
                cur->put(word[i], new Node());
            }

            cur = cur->getRef(word[i]);
            cur->c++;
        }

        cur->setEnd();
    }

    bool search(string word)
    {
        Node *cur = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!cur->containsKey(word[i]))
            {
                return false;
            }

            cur = cur->getRef(word[i]);
        }

        return cur->getEnd();
    }

    bool startsWith(string prefix)
    {
        Node *cur = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (!cur->containsKey(prefix[i]))
            {
                return false;
            }

            cur = cur->getRef(prefix[i]);
        }

        return true;
    }
};