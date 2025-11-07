#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *prev, *next;
    Node(char c) : data(c), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(char c)
    {
        Node *nn = new Node(c);
        if (!head)
        {
            head = nn;
            return;
        }
        Node *t = head;
        while (t->next)
            t = t->next;
        t->next = nn;
        nn->prev = t;
    }

    bool isPalindrome()
    {
        if (!head)
            return true;
        Node *left = head, *right = head;
        while (right->next)
            right = right->next;
        while (left && right && left != right && right->next != left)
        {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main()
{
    DoublyLinkedList dll;
    string s = "level";
    for (char c : s)
        dll.insert(c);
    cout << (dll.isPalindrome() ? "True" : "False") << endl;
    return 0;
}
