#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
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

    void push_back(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* swapNodes(int x, int y) {
        if (x == y) return head;
        Node* prevX = NULL, *currX = head;
        Node* prevY = NULL, *currY = head;
        int pos = 1;

        // Find the xth node
        while (currX && pos != x) {
            prevX = currX;
            currX = currX->next;
            pos++;
        }

        // Reset position counter and find the yth node
        pos = 1;
        while (currY && pos != y) {
            prevY = currY;
            currY = currY->next;
            pos++;
        }

        // If either x or y is out of range
        if (currX == NULL || currY == NULL)
            return head;

        // If x is not the head of the list
        if (prevX != NULL)
            prevX->next = currY;
        else // make y the new head
            head = currY;

        // If y is not the head of the list
        if (prevY != NULL)
            prevY->next = currX;
        else // make x the new head
            head = currX;

        // Swap next pointers
        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;

        return head;
    }
};

int main() {
    List l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);

    l1.printList();

    l1.head = l1.swapNodes(2, 5);    
    l1.printList();

    return 0;
}
