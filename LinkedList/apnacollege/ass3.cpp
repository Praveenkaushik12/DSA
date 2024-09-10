#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

    ~Node(){
       
    }
};

class List{
public:
    Node* head;
    Node* tail;

    List(){
        head=NULL;
        tail=NULL;
    }

    ~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
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

Node* swapLL(Node* head,int x,int y){
    if(x==y){
        return head;
    }
    Node* temp=head;
    
    Node* prev=NULL;
    Node* nxt=NULL;
    int count=1;
    while(count!=x){
        temp=temp->next;
        count++;
    }
    Node* temp1=temp;
    while(count<y ||count==y){
        temp1=temp1->next;
        count++;
    }
    prev=temp1;
    count=x;
    Node* curr=temp;

    while(count<=y){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        count++;
    }

    head->next=prev;

    return head;

}



int main(){
    List l1;
    List l2;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    l1.printList();
    l1.head=swapLL(l1.head,1,5);
    
    l1.printList();

    return 0;
}