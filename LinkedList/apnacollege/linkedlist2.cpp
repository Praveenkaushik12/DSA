#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    ~Node()
    {
        // cout<<"~Node"<<data<<endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        // cout<<"~List"<<endl;
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
    void insertatBeg(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertatBack(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


void removeCycle(Node *head){
    Node* slow=head;
    Node* fast=head;

    bool isCycle=false;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            cout<<"Cycle exits"<<endl;
            isCycle=true;
            break;
        }

    } 

    if(!isCycle){
        cout<<"Cycle doesn't exits";
        return;
    }

    slow=head;

    if(slow==fast){

        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;

    }else{
        Node* prev=fast;
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }

        prev->next=NULL;
    }
}


int main()
{
    List l1;
    l1.insertatBeg(3);
    l1.insertatBeg(2);
    l1.insertatBeg(1);
    l1.insertatBack(4);
    removeCycle(l1.head);  
    l1.printList();

   

    return 0;
}