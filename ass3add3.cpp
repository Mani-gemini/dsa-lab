/*Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the
array in order of their appearance in the array. Note: The Next Greater Element for an element x is
the first greater element on the right side of x in the array. Elements for which no greater element
exist, consider the next greater element as -1.  */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    int size;
    int grtr = -1;
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
    for (int i = 0; i < size; i++)
    {
        s.push(arr[i]);
    }
    while (s.top() != num)
    {
        if (s.top() > num)
        {
            grtr = s.top();
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
    cout << "Next greater element is: " << grtr;
    return 0;
}