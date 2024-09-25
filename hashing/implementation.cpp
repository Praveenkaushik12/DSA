#include<iostream>
using namespace std;

class Node{
public:
    string key;
    int value;
    Node* next;

    Node(string key,int value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node(){
        Node* temp = this;
        while(temp != NULL){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

class HashTable{
    size_t totalSize;
    size_t currSize;
    Node** table;

    int hashfunction(string key){
        int index = 0;
        int prime = 31;
        int p_pow = 1;

        for(char ch : key){
            index = (index + (ch * p_pow) % totalSize) % totalSize;
            p_pow = (p_pow * prime) % totalSize;
        }
        return index;
    }

public:
    HashTable(size_t size){
        totalSize = size;
        currSize = 0;
        table = new Node*[totalSize];
        for(size_t i = 0; i < totalSize; i++){
            table[i] = NULL;
        }
    }

    void rehash(){
        Node** oldTable = table;
        size_t oldSize = totalSize;

        totalSize = 2 * totalSize;
        currSize = 0;
        table = new Node*[totalSize];

        for(size_t i = 0; i < totalSize; i++){
            table[i] = NULL;
        }

        // Copy old table to new
        for(size_t i = 0; i < oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }
        }
        delete[] oldTable;
    }

    void insert(string key, int value){
        int idx = hashfunction(key);

        Node* newNode = new Node(key, value);
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totalSize;

        if(lambda > 0.7){  // Rehash when 70% full
            rehash();
        }
    }

    bool exists(string key){
        int idx = hashfunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key){
        int idx = hashfunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    void remove(string key){
        int idx = hashfunction(key);
        Node* temp = table[idx];
        Node* prev=temp;

        while(temp!=NULL){ //O(lambda)
            if(temp->key ==key){
                if(prev==temp){
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                break;
            }

            prev=temp;
            temp=temp->next;
        }

    }

    void print(){
        for(size_t i = 0; i < totalSize; i++){
            cout << "index " << i << " -> ";
            Node* temp = table[i];
            while(temp != NULL){
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    HashTable hash(5);

    hash.insert("India", 150);
    hash.insert("China", 140);
    hash.insert("UK", 100);
    hash.insert("Russia", 50);
    hash.insert("US", 10);

    hash.remove("India");

    if(hash.exists("India")){
        cout << hash.search("India") << endl;
    }
    hash.print();
    return 0;
}
