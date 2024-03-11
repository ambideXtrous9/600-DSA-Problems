// Cpp program to find first repeated word in a string
#include<bits/stdc++.h>
using namespace std;



void solve(string s)
{
	unordered_map<string,int> M; // to store occurrences of word

    int n = s.length();
    char spaceman = ' ';
	string t="";
	
    for(int i=0;i<n;i++)
	{

        while(s[i]!=spaceman && i<n)
        {
            t += s[i++];

        }
		
        if(M.find(t)!=M.end())
        {
            cout<<t<<endl;
            return;
        }
        else
        {
            M[t]++;
            t = "";
        }
	}
	cout<<"No Repetition\n";
}
int main()
{
	string u="Ravi had been saying that he had been there";
	string v="Ravi had been saying that";
	string w="love had love had";
	solve(u);
	solve(v);
	solve(w);
	
	
	return 0;
	
}
