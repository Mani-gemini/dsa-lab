/*Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek(). */
#include <iostream>
using namespace std;

#define SIZE 10 

class CircularQueue
{
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is FULL! Cannot enqueue " << val << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = val;
        cout << val << " enqueued successfully."<<endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY!\n";
        }
        else
        {
            cout << "Front element = " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, val;

    while (1)
    {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
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
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
            break;
        case 5:
            cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT full\n");
            break;
        case 6:
            q.display();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
