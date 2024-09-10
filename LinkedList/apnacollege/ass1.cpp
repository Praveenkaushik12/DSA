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
        if(next!=NULL){
            delete next;
            next=NULL;
        }
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

    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
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


// int getSize(Node* head){
//     int size=0;

//     while(head!=NULL){
//         head=head->next;
//         size++;
//     }

//     return size;
// }

Node* getIntersectionPoint(Node* headA, Node* headB) {
    while (headB) {
        Node* temp = headA;
        while (temp) {

            if (temp == headB)
                return headB;
            temp = temp->next;
        }
        headB = headB->next;
    }

    return NULL;
}
void DeleteNnode(List l1,int M,int N){
    Node* t1=l1.head;
    while(M-1>0){
        t1=t1->next;
        M--;
    }
    Node* temp=t1->next;

    while(N-1>0){
        temp=temp->next;
        N--;
    }

    t1->next=temp->next;

    l1.printList();
    
    
}

int main(){
    List l1;
    List l2;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    Node* intersectNode = new Node(6);

    l1.tail->next = intersectNode;
    l1.tail = intersectNode;
    l1.push_back(7);
    l2.push_back(4);
    l2.push_back(5);
    l2.tail->next = intersectNode;
    l2.tail = intersectNode;

    l1.printList();
    l2.printList();

    cout<<getIntersectionPoint(l1.head,l2.head)->data;

    return 0;
}