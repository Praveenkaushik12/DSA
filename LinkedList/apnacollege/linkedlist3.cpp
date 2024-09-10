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

Node* merge(Node* left,Node* right){
    List ans;
    Node* i=left;
    Node* j=right;

    while(i!=NULL && j!=NULL){
        if(i->data<=j->data){
            ans.push_back(i->data);
            i=i->next;
        }else{
            ans.push_back(j->data);
            j=j->next;
        }  
    }
    while(i!=NULL){
        ans.push_back(i->data);
        i=i->next;
    }

    while(j!=NULL){
        ans.push_back(j->data);
        j=j->next;
    }

    return ans.head;
}

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

Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }


    Node* righthead=splitAtMid(head);

    Node* left=mergeSort(head);
    Node* right=mergeSort(righthead);

    return merge(left,right);
}


int main()
{
    List l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.push_front(4);
    l1.printList();
    l1.head=mergeSort(l1.head);
    l1.printList();

   

    return 0;
}