// Doubly Linked List C++ Code

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int x)
    {
        value = x;
        next = NULL;
        prev = NULL;
    }
};

void forwardTraversal(Node* head)
{
    Node* temp = head;
    while (temp)
    {
        cout<<temp->value<<"-";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}

void backwardTraversal(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp->value<<"-";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
};

void insertAtStart(Node* &head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
};
void insertAtEnd(Node* &head, int val)
{
    Node *newNode = new Node(val);
    Node *lastNode = head;

    while (lastNode->next)
    {
        lastNode = lastNode->next;
    };

    
    lastNode->next = newNode;
    newNode->prev = lastNode;

};

void insertAtMiddle(Node* &head, int val, int k)
{
    if(k == 1)
    {
        insertAtStart(head, val);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < k-1; i++)
    {
        temp = temp->next;
    }
    
    Node *newNode = new Node(val);
    if(temp->next)
    {
        temp->next->prev = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* tail = new Node(4);
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = tail;
    tail->prev = n3;
    Node* head = n1;
    
    // forwardTraversal(head);
    // backwardTraversal(tail);

    // insertAtStart(head, 69);
    // forwardTraversal(head);

    // forwardTraversal(head);
    // insertAtEnd(head, 101);
    // forwardTraversal(head);

    forwardTraversal(head);
    insertAtMiddle(head, 696, 3);
    forwardTraversal(head);

};
