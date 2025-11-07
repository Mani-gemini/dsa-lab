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
public:
    Node *head;
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

    void display(Node *h = nullptr)
    {
        if (!h)
            h = head;
        if (!h)
        {
            cout << "Empty list\n";
            return;
        }
        Node *temp = h;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != h);
        cout << endl;
    }

    Node *split()
    {
        if (!head || head->next == head)
            return nullptr;

        Node *slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next->next == head)
            fast = fast->next;

        Node *head1 = head;
        Node *head2 = slow->next;
        fast->next = head2;
        slow->next = head1;
        return head2;
    }
};

int main()
{
    CircularLinkedList list;
    list.insertAtTail(10);
    list.insertAtTail(4);
    list.insertAtTail(9);
    cout << "Original Circular Linked List:\n";
    list.display();
    Node *head2 = list.split();
    cout << "\nFirst half: ";
    list.display(list.head);
    cout << "Second half: ";
    list.display(head2);

    return 0;
}
