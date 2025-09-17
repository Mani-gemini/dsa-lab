#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class singleLL
{
    node *head;

public:
    singleLL()
    {
        head = nullptr;
    }

    void append(int value)
    {
        node *newnode = new node(value);
        if (!head)
        {
            head = newnode;
            return;
        }
        node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newnode;
    }

    void display()
    {
        node *curr = head;
        while (curr)
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
    void reverseList()
    {
        node *prev = NULL;
        node *curr = head;
        while (curr)
        {
            node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }
};
int main()
{
    cout << "question 4" << endl;
    node *head = NULL;
    singleLL list;
    for (int i = 1; i <= 4; i++)
        list.append(i);

    cout << "Original List: ";
    list.display();
    list.reverseList();
    cout << "Reversed List: ";
    list.display();
    return 0;
}
