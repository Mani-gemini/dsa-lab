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

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
    void correctNode()
    {
        Node *temp = head;
        while (temp && temp->next)
        {
            if (temp->next->prev != temp)
            {
                temp->next->prev = temp;
                cout << "Fixed wrong pointer at node with data " << temp->next->data << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No correction needed.\n";
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.head->next->next->prev = nullptr;
    cout << "Original DLL:\n";
    dll.display();
    dll.correctNode();
    cout << "\nAfter correction:\n";
    dll.display();

    return 0;
}
