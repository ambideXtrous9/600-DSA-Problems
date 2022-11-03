#include <bits/stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{

    unordered_set<string> dict(wordList.begin(), wordList.end());

    queue<string> todo;

    todo.push(beginWord);

    int ladder = 0;

    if (dict.find(endWord) == dict.end())
        return 0;

    while (!todo.empty())
    {
        ladder++;
        int n = todo.size();
        for (int i = 0; i < n; i++)
        {
            string word = todo.front();
            todo.pop();

            for (int j = 0; j < word.size(); j++)
            {
                char c = word[j];
                for (int k = 0; k < 26; k++)
                {
                    word[j] = 'a' + k;
                    
                    if (word == endWord)
                        return ladder + 1;
                    
                    if (dict.find(word) != dict.end())
                    {
                        dict.erase(word);
                        todo.push(word);
                    }
                }
                word[j] = c;
            }
        }
    }
    return 0;
}