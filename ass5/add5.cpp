#include <iostream>
using namespace std;
class node
{
public:
    int coeff;
    int exp;
    node *next;
    node(int c, int e)
    {
        coeff = c;
        exp = e;
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

    void append(int value1, int value2)
    {
        node *newnode = new node(value1, value2);
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
            cout << curr->coeff << "^" << curr->exp << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};
node *sumpoly(node *head1, node *head2)
{
    if (head1 == nullptr && head2 == nullptr)
    {
        return nullptr;
    }
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }
    node *temp1 = head1;
    node *temp2 = head2;
    singleLL list;
    while (temp1 || temp2)
    {
        if (temp1->exp == temp2->exp)
        {
            list.append(temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            list.append(temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else
        {
            list.append(temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }
    return list.head;
}
int main()
{
    singleLL poly1;
    singleLL poly2;
    poly1.append(5, 2);
    poly1.append(4, 1);
    poly1.append(2, 0);
    poly2.append(5, 1);
    poly2.append(5, 0);
    poly1.display();
    poly2.display();
    singleLL sum;
    sum.head=sumpoly(poly1.head,poly2.head);
    sum.display();
}
