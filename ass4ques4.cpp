/*Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
b c Sample O/P: a -1 b b */
#include <bits/stdc++.h>
using namespace std;
void fnr(string s)
{
    queue<char> q;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        freq[(s[i]) - 'a']++;
        q.push(s[i]);
        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << q.front() << " ";
        }
    }
}
int main()
{
    string str = "aabc";
    cout << "output : ";
    fnr(str);
    return 0;
}
