/*Given an array A, find the nearest smaller element for every element A[i] in the array such that the
element has an index smaller than i.*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int num;
    cout << "enter number to find nearest smaller element: ";
    cin >> num;
    for (int i = size; i > 0; i--)
    {
        s.push(arr[i]);
    }
    while (!s.empty())
    {
        if (s.top() < num)
        {
            cout << "Nearest smaller element is: " << s.top();
            break;
        }
        s.pop();
    }
}
