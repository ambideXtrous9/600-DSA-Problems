#include <bits/stdc++.h>

using namespace std;


bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        return false;

    queue<char> q1;
    queue<char> q2;

    for (int i = 0; i < s.size(); i++)
    {
        q1.push(s[i]);
        q2.push(goal[i]);
    }

    int k = goal.size();

    while (k--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}
int main()
{
    string s1 = "ABCD";
    string s2 = "CDAB";
    if (check_rotation(s1, s2))
        cout << s2 << " is a rotated form of " << s1
             << endl;
    else
        cout << s2 << " is not a rotated form of " << s1
             << endl;
    string s3 = "ACBD";
    if (check_rotation(s1, s3))
        cout << s3 << " is a rotated form of " << s1
             << endl;
    else
        cout << s3 << " is not a rotated form of " << s1
             << endl;
    return 0;
}

bool areRotations(string str1, string str2)
{
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

/* Driver program to test areRotations */
int main()
{
    string str1 = "AACD", str2 = "ACDA";
    if (areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}