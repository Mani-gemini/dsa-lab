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
    int countElement()
    {
        int count = 0;
        if (!head)
        {
            cout << "0 elements in LL" << endl;
            return -1;
        }
        node *temp;
        temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void middle(){
        int c=countElement();
        int index=0;
        node* temp=head;
        for (int i = 0; i < c/2; i++)
        {
            temp=temp->next;
        }
        cout<<"Middle element is "<<temp->val<<endl;
    }
};
int main()
{
    cout << "Question 3" << endl;
    singleLL list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.display();
    list.middle();
    return 0;
}
