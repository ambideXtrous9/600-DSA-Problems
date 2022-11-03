#include <bits/stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    
    queue<string> todo;
   
    todo.push(beginWord);
    
    
    int ladder = 1;  // level
   

   // BFS
    while (!todo.empty())
    {
        int n = todo.size();
        
        for (int i = 0; i < n; i++)
        {
            string word = todo.front();
            todo.pop();
            
            if (word == endWord)
            {
                return ladder;
            }
            
            dict.erase(word);
            
            for (int j = 0; j < word.size(); j++)
            {
                char c = word[j];
                
                for (int k = 0; k < 26; k++)
                {
                    if('a'+k == c) continue;
                    
                    word[j] = 'a' + k;

                    if (word == endWord)   // reached the end word.
                        return ladder + 1;


                    if (dict.find(word) != dict.end())
                    {
                        todo.push(word);
                    }
                }
                
                word[j] = c;  // backtrack revert back the altered char
            }
        }

        ladder++; // next level 
    }

    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // put dict words to UO set
    unordered_set<string> dict(wordList.begin(), wordList.end());
    
    // start BFS with begin word
    queue<string> todo;
    
    todo.push(beginWord);
    
    // ladder denotes the level
    int ladder = 0;
    
    // if end does not exist in dict
    if (dict.find(endWord) == dict.end())
        return 0;
    
    while (!todo.empty())
    {
        ladder++;             //increment level 
        
        int n = todo.size();

        for (int i = 0; i < n; i++)   // line by line BFS
        {
            string word = todo.front();
            todo.pop();

            for (int j = 0; j < word.size(); j++) // for altering every char
            {
                char c = word[j];

                for (int k = 0; k < 26; k++)  // altering char with other alphabet
                {
                    if(c=='a' + k) continue;

                    word[j] = 'a' + k;
                    
                    if (word == endWord)   // reached the end word.
                        return ladder + 1;
                    
                    if (dict.find(word) != dict.end())
                    {
                        dict.erase(word);
                        todo.push(word);
                    }
                }

                word[j] = c;  // restoring back that char like backtrack
            }
        }
    }
    return 0;
}