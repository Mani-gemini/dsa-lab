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

    void countAndDelete(int key)
    {
        int count = 0;
        while (head && head->val == key)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        node *curr = head;
        while (curr && curr->next)
        {
            if (curr->next->val == key)
            {
                node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
                count++;
            }
            else
            {
                curr = curr->next;
            }
        }

        cout << "Deleted " << count << " nodes with value " << key << endl;
    }
};

int main()
{
    cout << "question 2" << endl;
    singleLL list;
    list.append(1);
    list.append(2);
    list.append(1);
    list.append(2);
    list.append(1);
    list.append(3);
    list.append(1);

    cout << "Original List: ";
    list.display();

    list.countAndDelete(1);

    cout << "After Deletion: ";
    list.display();

    return 0;
}
