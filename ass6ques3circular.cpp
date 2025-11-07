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

    int getSize()
    {
        if (!head)
            return 0;
        int count = 0;
        Node *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
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
    cll.insertAtTail(5);
    cll.insertAtTail(10);
    cll.insertAtTail(15);

    cout << "Circular Linked List: ";
    cll.display();
    cout << "Size of Circular Linked List = " << cll.getSize() << endl;
    return 0;
}
