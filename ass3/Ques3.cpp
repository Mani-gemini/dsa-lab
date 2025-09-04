#include <bits/stdc++.h>
using namespace std;

#define MAX 100

char stackArr[MAX];
int top = -1;

void push(char c)
{
    if (top < MAX - 1)
    {
        stackArr[++top] = c;
    }
}

char pop()
{
    if (top == -1)
        return '\0';
    return stackArr[top--];
}

int isBalanced(const char *expr)
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            char t = pop();
            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '['))
            {
                return 0;
            }
        }
    }
    return (top == -1);
}

int main()
{
    char expr[MAX];
    cout << "Enter an expression: ";
    cin.getline(expr, MAX);

    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
