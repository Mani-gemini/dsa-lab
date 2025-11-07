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

    int countParity(int n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
                count++;
            n /= 2;
        }
        return count;
    }

    void removeEvenParityNodes()
    {
        if (!head)
            return;

        Node *curr = head, *prev = nullptr;
        bool firstIteration = true;

        do
        {
            Node *nextNode = curr->next;
            int parity = countParity(curr->data);

            if (parity % 2 == 0)
            {
                if (curr == head && curr->next == head)
                {
                    delete curr;
                    head = nullptr;
                    return;
                }

                if (curr == head)
                {
                    Node *last = head;
                    while (last->next != head)
                        last = last->next;
                    head = head->next;
                    last->next = head;
                    delete curr;
                    curr = head;
                }
                else
                {
                    prev->next = curr->next;
                    delete curr;
                    curr = nextNode;
                }
            }
            else
            {
                prev = curr;
                curr = nextNode;
            }

            if (!head)
                break;
            if (curr == head && !firstIteration)
                break;
            firstIteration = false;
        } while (true);
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
    cll.insertAtTail(9);
    cll.insertAtTail(11);
    cll.insertAtTail(34);
    cll.insertAtTail(6);
    cll.insertAtTail(13);
    cll.insertAtTail(21);

    cout << "Original CLL: ";
    cll.display();

    cll.removeEvenParityNodes();

    cout << "After removal: ";
    cll.display();
    return 0;
}
