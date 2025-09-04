#include <bits/stdc++.h>
using namespace std;
string checkAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return "NOT ANAGRAM";
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2)
    {
        return "ANAGRAM";
    }
    return "NOT ANAGRAM";
}

int main()
{

    string str1, str2;
    cout<<"Enter two strings: ";
    cin >> str1 >> str2;
    cout << checkAnagram(str1, str2) << endl;

    return 0;
}
