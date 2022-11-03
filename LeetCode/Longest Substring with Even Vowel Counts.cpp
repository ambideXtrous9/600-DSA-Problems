#include <bits/stdc++.h>

using namespace std;

// vowel : a e i o u
// o/e   : 2 2 2 2 2 = 2^5 = 32


int solve(string s) 
{
     unordered_map<char,int> vowel;
        
        vowel['a'] = 0; // 1
        vowel['e'] = 1; // 2
        vowel['i'] = 2; // 4
        vowel['o'] = 3; // 8
        vowel['u'] = 4; // 16
        
        unordered_map<int,int> M;
        M[0] = -1;
        int mask = 0;
        int n = s.length();
        int max_len = 0;
        for(int i = 0; i < n; i++)
        {
            if(vowel.find(s[i]) != vowel.end())
            {
                mask ^= (1<<vowel[s[i]]);    // calculating bit mask
                
                if(M.find(mask) == M.end())  // if not already present in map
                    M[mask] = i;
            }
            max_len = max(max_len,i - M[mask]); // when odd then i == M[mask] -> 0
            
        }
        return max_len;
    
}