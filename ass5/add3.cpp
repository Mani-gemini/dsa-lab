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
public:
    node *head;

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
};
void removeLoop(node* head) {
    if (head == NULL || head->next == NULL)
        return;
    node* slow = head;
    node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return;
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}
int main()
{
    singleLL list;
    list.append(1);
    list.append(7);
    list.append(3);
    list.append(6);
    // Creating a loop manually: 5 → 3
    node *temp = list.head;
    node *loopNode = nullptr;
    while (temp->next)
    {
        if (temp->val == 3)
            loopNode = temp;
        temp = temp->next;
    }
    temp->next = loopNode; // Creates loop

    // Detect and remove loop
    removeLoop(list.head);

    // Verify list after removal
    cout << "\nLinked list after removing loop:\n";
    list.display();

    return 0;
}

