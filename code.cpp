#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;

    Node(int v)
    {
        value = v;
        next = NULL;
    }
};

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL";
};
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
};
void insertAtEnd(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        cout << "IF condition exicuted!";
        return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
};

void insertAtMiddle(Node* &head, int val, int position){
    
    Node* newNode = new Node(val);
    Node* prev = head;
    int count = 1;

    while(count<(position-1)){
        prev = prev->next;
        count++;
    }

    //Here is the main swaping of pointers
    newNode->next = prev->next;
    prev->next = newNode;
};

void deleteAtHead(Node* &head){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node* &head){
    if (head == NULL)
    {
        cout<<"List is empty!";
        return;
    }
    if (head->next == NULL)
    {
        cout<<"List has only one node!";
        delete head;
        head = NULL;
        return;
    }

    Node* secondLast = head;

    while(secondLast->next->next != NULL){
        secondLast = secondLast->next;
    }

    Node* lastNode = secondLast->next;
    secondLast->next = NULL;

    delete lastNode;
    
};

void deleteAtMiddle(Node* &head, int position){
    if(position=1){
        deleteAtHead(head);
        return;
    }
    Node* prev = head;
    int count = 1;
    while(count<(position-1)){
        prev = prev->next;
        count++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;

    delete curr;

};

void update(Node* &head, int val, int position){
    Node* temp = head;
    int count = 1;
    while(count<position){
        temp = temp->next;
        count++;
    }

    temp->value = val;
};

void deleteAlternateNode(Node* &head){
    Node* temp = head;
    while (temp!=NULL && temp->next!=NULL){
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        delete deleteNode;
    }
    
};

int findMiddleNode(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    //Now slow is at middle of Node!
    return slow->value;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    Node *head = node1;

    cout<<"After Inserting at End!"<<endl;
        insertAtEnd(head, 4);
        traverse(head);
    
    cout<<endl<<"After Inserting at start!"<<endl;
        insertAtHead(head, 0);
        traverse(head);
        
    cout<<endl<<"After Inserting in the middle!"<<endl;
        insertAtMiddle(head, 69, 3);
        traverse(head);
        
    cout<<endl<<"After Deleting at the start!"<<endl;
        deleteAtHead(head);
        traverse(head);                        
    
    cout<<endl<<"After Deleting at the End!"<<endl;
        deleteAtEnd(head);
        traverse(head);                           
    
    cout<<endl<<"After Deleting at the Middle!"<<endl;
        deleteAtMiddle(head, 3);
        traverse(head);                           
    
    cout<<endl<<"After Updating the Value.!"<<endl;
        update(head, 79, 1);
        traverse(head);                           
        
    cout<<endl<<"The Middle Node is :"<<findMiddleNode(head)<<endl;

    cout<<endl<<"After deleting Alternate Node.!"<<endl;
        deleteAlternateNode(head);
        traverse(head);                           

    return 0;
};
