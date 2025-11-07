#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList() : head(nullptr) {}

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int countParity(int n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
                count++;
            n = n / 2;
        }
        return count;
    }

    void removeEvenParityNodes()
    {
        Node *temp = head;
        while (temp)
        {
            int parity = countParity(temp->data);
            if (parity % 2 == 0)
            {
                Node *del = temp;
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                temp = temp->next;
                delete del;
            }
            else
                temp = temp->next;
        }
    }

    void display()
    {
        Node *t = head;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertAtTail(18);
    dll.insertAtTail(15);
    dll.insertAtTail(8);
    dll.insertAtTail(9);
    dll.insertAtTail(14);

    cout << "Original DLL: ";
    dll.display();

    dll.removeEvenParityNodes();

    cout << "After removal: ";
    dll.display();
    return 0;
}
