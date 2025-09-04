#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    int isEmpty()
    {
        return (top == -1) ? 1 : 0;
    }

    int isFull()
    {
        return (top == MAX - 1) ? 1 : 0;
    }

    void push(char c)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << c << endl;
        }
        else
        {
            arr[++top] = c;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        else
        {
            return arr[top--];
        }
    }
};

int main()
{
    char str[MAX];
    cout << "Enter a string: ";
    cin.getline(str, MAX);
    Stack s;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        s.push(str[i]);
    }
    cout << "Reversed string: ";
    for (int i = 0; i < len; i++)
    {
        cout << s.pop();
    }
    cout << endl;
    return 0;
}
