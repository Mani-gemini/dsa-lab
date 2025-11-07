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
node* rotateK(node* head,int k){
    node*temp=head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    for (int i = 0; i < len-k; i++)
    {
        node*front=head;
        node*last=head;
        while (last->next->next)
        {
            last=last->next;
        }
        last->next->next=front;
        head=last->next;
        last->next=nullptr;
    }
    return head;
}
int main(){
    singleLL list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.display();
    list.head=rotateK(list.head,4);
    list.display();
}