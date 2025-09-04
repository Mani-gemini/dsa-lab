#include <iostream>
using namespace std;
class Stack
{
    int arr[10];
    int top;

public:
    Stack() { top = -1; }

    int isEmpty()
    {
        return (top == -1) ? 1 : 0;
    }

    int isFull()
    {
        return (top == 10 - 1) ? 1 : 0;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "\nStack Overflow! Cannot push " << val << endl;
        }
        else
        {
            arr[++top] = val;
            cout << val << " pushed to stack" << endl;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow! Cannot pop" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty! No top element" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty!" << endl;
        }
        else
        {
            cout << "\nStack elements (top to bottom):" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack s;
    int choice, val;

    while (1)
    {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;

        case 2:
            val = s.pop();
            if (val != -1)
                cout << "Popped element: " << val << endl;
            break;

        case 3:
            val = s.peek();
            if (val != -1)
                cout << "Top element: " << val << endl;
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            exit(0);

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
