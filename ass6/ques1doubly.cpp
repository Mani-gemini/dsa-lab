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
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head)
        {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
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
    void insertAfter(int key, int val)
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node not found\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    void insertBefore(int key, int val)
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node not found\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }
    void deleteNode(int val)
    {
        if (!head)
        {
            cout << "List empty\n";
            return;
        }
        Node *temp = head;
        while (temp && temp->data != val)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node not found\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }
    bool search(int val)
    {
        Node *t = head;
        while (t)
        {
            if (t->data == val)
                return true;
            t = t->next;
        }
        return false;
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
    int ch, val, key;
    while (true)
    {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Head\n2. Insert at Tail\n3. Insert After Node\n4. Insert Before Node\n";
        cout << "5. Delete Node\n6. Search Node\n7. Display\n8. Exit\nChoice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtHead(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtTail(val);
            break;
        case 3:
            cout << "After which value: ";
            cin >> key;
            cout << "Value to insert: ";
            cin >> val;
            dll.insertAfter(key, val);
            break;
        case 4:
            cout << "Before which value: ";
            cin >> key;
            cout << "Value to insert: ";
            cin >> val;
            dll.insertBefore(key, val);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> val;
            dll.deleteNode(val);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (dll.search(val) ? "Found\n" : "Not Found\n");
            break;
        case 7:
            dll.display();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
