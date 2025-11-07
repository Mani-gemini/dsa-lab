#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val)
    {
        Node *nn = new Node(val);
        if (!head)
        {
            head = nn;
            return;
        }
        Node *t = head;
        while (t->next)
            t = t->next;
        t->next = nn;
    }

    Node *getHead() { return head; }

    void makeCircular()
    {
        if (!head)
            return;
        Node *t = head;
        while (t->next)
            t = t->next;
        t->next = head;
    }

    bool isCircular()
    {
        if (!head)
            return false;
        Node *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main()
{
    LinkedList l;
    l.insert(2);
    l.insert(4);
    l.insert(6);
    l.insert(7);
    l.insert(5);
    l.makeCircular();
    cout << (l.isCircular() ? "True" : "False") << endl;
    return 0;
}