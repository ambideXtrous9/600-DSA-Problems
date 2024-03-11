#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin>>str;

    string ans = "";

    unordered_map<char,char> M;
    int idx = 0;
    
    for(auto c : str)
    {
        if(M.find(c) == M.end())
        {
            M[c] = char('A'+idx);
            ans += M[c];
            idx++;
        }
        else
            ans += M[c];
    }

    cout<<ans<<endl;

}