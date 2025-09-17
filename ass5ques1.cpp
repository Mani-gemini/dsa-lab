#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() { head = NULL; }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
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
    }

    void insertAfter(int key, int val)
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int val)
    {
        if (!head)
            return;
        if (head->data == key)
        {
            insertAtBeginning(val);
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (!temp->next)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteNode(int key)
    {
        if (!head)
            return;
        if (head->data == key)
        {
            deleteFromBeginning();
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (!temp->next)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    void searchNode(int key)
    {
        Node *temp = head;
        int pos = 1;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    SinglyLinkedList list;
    int choice, val, key;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before key\n4. Insert after key\n";
        cout << "5. Delete from beginning\n6. Delete from end\n7. Delete specific node\n";
        cout << "8. Search node\n9. Display list\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertBefore(key, val);
            break;
        case 4:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertAfter(key, val);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter key: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 8:
            cout << "Enter key: ";
            cin >> key;
            list.searchNode(key);
            break;
        case 9:
            list.display();
            break;
        }
    } while (choice != 0);

    return 0;
}
