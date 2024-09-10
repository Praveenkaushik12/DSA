#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    //constructor
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<< value <<endl;
    }
};

void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* & tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail=temp;
}

void insertAtPosition(Node* &tail, Node* &head,int position,int d){

    //insertion at start
    if(position==1){
        insertAtHead(head,d);
        return;
    }


    Node* temp = head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert= new Node(d);
    nodeToInsert->next = temp->next;
    temp-> next = nodeToInsert; 
}


void deleteNode(int position,Node* & head){
    if(position ==1){
        Node* temp = head;
        head= head -> next;
        //memory free 
        temp -> next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev =curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr ->next;
        curr-> next =NULL;
        delete curr;
    }
}

void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10); 
    Node* head = node1;
    Node* tail = node1;
    display(head);
    insertAtTail(tail, 15 );
    display(head);
    insertAtTail(tail,20);
    display(head);

    insertAtPosition(tail,head,3,22);
    display(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    deleteNode(1,head);
    display(head);

    deleteNode(3,head);
    display(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    return 0;
} 