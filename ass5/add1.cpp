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
node *find_intersection(node *head1, node *head2)
{
    int len1 = 0, len2 = 0;
    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }
    int diff = abs(len1 - len2);
    temp1 = head1;
    temp2 = head2;
    // as length of list after the intersection point is same so we make length of both pointers same
    if (len1 > len2)
        while (diff--)
            temp1 = temp1->next;
    else
        while (diff--)
            temp2 = temp2->next;
    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}
// main is written by AI 
int main()
{
    cout << "Assignment 5" << endl;

    // Create first linked list: 4 -> 1 -> 8 -> 5
    singleLL list1;
    list1.append(4);
    list1.append(1);
    list1.append(8);
    list1.append(5);

    // Create second linked list: 5 -> 6 -> 1
    singleLL list2;
    list2.append(5);
    list2.append(6);
    list2.append(1);

    // Create a common intersection part: 8 -> 5
    node *common1 = new node(8);
    node *common2 = new node(5);
    common1->next = common2;

    // Manually connect lists to create intersection
    // For list1: 4 -> 1 -> (common1)
    node *temp1 = list1.head;
    while (temp1->next)
        temp1 = temp1->next;
    temp1->next = common1;

    // For list2: 5 -> 6 -> 1 -> (common1)
    node *temp2 = list2.head;
    while (temp2->next)
        temp2 = temp2->next;
    temp2->next = common1;

    // Display both lists (for visualization)
    cout << "List A: ";
    list1.display();
    cout << "List B: ";
    list2.display();

    // Find intersection
    node *intersection = find_intersection(list1.head, list2.head);

    if (intersection)
        cout << "Intersected at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found.\n";

    return 0;
}
