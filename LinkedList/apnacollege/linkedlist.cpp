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
        cout<<"~Node"<<data<<endl;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }

    ~List(){
        cout<<"~List"<<endl;
        if(head!=NULL){
            delete head;
            head=NULL;
        }

    }
    void insertatBeg(int data){
    Node* newNode=new Node(data);

    if(head==NULL){
        head=tail=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
}

void insertatBack(int data){
    Node* newNode=new Node(data);

    if(head==NULL){
        head=tail=newNode;
    }else{
        tail->next=newNode;
        tail=newNode;
    }
}
void printList(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int helper(Node* head,int key){
    if(head==NULL){
        return -1;
    }
    if(head->data==key){
        return 0;
    }
    int idx=helper(head->next,key);
    if(idx==-1){
        return -1;
    } 
    return idx+1;
}

int searchKey(int key){
    return helper(head,key);
}

void reverse(){
    Node* curr=head;
    Node* prev=NULL;
    Node* nxt;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
}

int getMiddle() {
        if (!head) {
            return -1; 
        }

        Node* slow = head;
        Node* fast = head;
        int index = 1; 

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            index++;
        }

        return index; 
    }
};




int main(){
    List l1;
    l1.insertatBeg(3);
    l1.insertatBeg(2);
    l1.insertatBeg(1);
    l1.insertatBack(4);
    l1.printList();
    cout<<l1.getMiddle();
    // l1.reverse();
    // l1.printList();
    // cout<<l1.searchKey(3)<<endl;

    return 0;
}