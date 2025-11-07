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
node* reverseLinkedListKGroup(node* head, int k) {
	node* currentNode = head;
	int totalNodes = 0;
	while (currentNode != NULL && totalNodes < k) {
		currentNode = currentNode->next;
		totalNodes++;
	}
	if (totalNodes < k) {
		return head;
	}
	currentNode = head;
	node* prevNode = NULL;
	node* nextNode;
	int nodeCount = 0;
	while (nodeCount < k) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
		nodeCount++;
	}
	head->next = reverseLinkedListKGroup(nextNode, k);
	return prevNode;	
}
int main()
{
    cout<<"assignment 5"<<endl;
    singleLL list;
    for (int i = 1; i <= 8; i++)
    {
        list.append(i);
    }
    list.display();
    list.head=reverseLinkedListKGroup(list.head,3);
    list.display();
    return 0;
}
