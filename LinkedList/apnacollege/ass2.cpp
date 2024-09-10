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



Node* deleteNodes(Node* head, int M, int N) {
    if (head == nullptr || M <= 0 || N < 0) {
        return head;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current) {
        // Skip M nodes
        for (int i = 1; i < M && current; ++i) {
            current = current->next;
        }

        // If we have reached the end of the list or there are fewer than M nodes
        if (!current || current->next == nullptr) {
            return head;
        }

        // Node after M nodes
        Node* temp = current->next;

        // Skip N nodes
        for (int i = 0; i < N && temp; ++i) {
            Node* nextNode = temp->next;
            delete temp; // Deleting the node
            temp = nextNode;
        }

        // Link the previous node to the node after skipped nodes
        current->next = temp;

        // Move previous to current position
        previous = current;
        current = temp;
    }

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
    Node* newhead=deleteNodes(l1.head,2,2);
    l1.head=newhead;
    l1.printList();

    return 0;
}