#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    void insertAfter(int key, int val)
    {
        if (!head)
            return;
        Node *temp = head;
        do
        {
            if (temp->data == key)
            {
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void deleteNode(int val)
    {
        if (!head)
            return;
        Node *curr = head, *prev = nullptr;
        do
        {
            if (curr->data == val)
                break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (curr->data != val)
        {
            cout << "Node not found\n";
            return;
        }

        if (curr == head && curr->next == head)
        {
            delete curr;
            head = nullptr;
            return;
        }

        if (curr == head)
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            head = head->next;
            temp->next = head;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
    }
    bool search(int val)
    {
        if (!head)
            return false;
        Node *temp = head;
        do
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    void display()
    {
        if (!head)
        {
            cout << "Empty list\n";
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    CircularLinkedList cll;
    int ch, val, key;
    while (true)
    {
        cout << "\n--- CIRCULAR LINKED LIST MENU ---\n";
        cout << "1. Insert at Head\n2. Insert at Tail\n3. Insert After\n";
        cout << "4. Delete Node\n5. Search Node\n6. Display\n7. Exit\nChoice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cll.insertAtHead(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            cll.insertAtTail(val);
            break;
        case 3:
            cout << "After which value: ";
            cin >> key;
            cout << "Value to insert: ";
            cin >> val;
            cll.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> val;
            cll.deleteNode(val);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (cll.search(val) ? "Found\n" : "Not Found\n");
            break;
        case 6:
            cll.display();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
