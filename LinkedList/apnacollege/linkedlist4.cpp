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
    void push_front(int data)
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

    void push_back(int data)
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

Node* splitAtMid(Node* head){
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }

    return slow;


}
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;  
    }

    return prev;
}

Node* zigZagLL(Node* head) {
    if (!head || !head->next) return head;

    Node* left = head;
    Node* rightheadLL = splitAtMid(head);
    Node* right = reverse(rightheadLL);

    while (left != NULL && right != NULL) {
        Node* nextleft = left->next;
        Node* nextright = right->next;

        left->next = right;
        if (nextleft == NULL) {
            right->next = NULL;
            break;
        }

        right->next = nextleft;

        left = nextleft;
        right = nextright;
    }

    return head;
}

int main()
{
    List l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.push_front(4);
    l1.printList();
    l1.head=zigZagLL(l1.head);

    l1.printList();

   

    return 0;
}