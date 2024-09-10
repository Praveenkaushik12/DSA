#include<iostream>
using namespace std;

class parent1 {
public:
    parent1() {
        cout << "Parent class1" << endl;
    }
};


class child1 : public parent1{
public:
    child1() : parent1(){
        cout << "Child Class1" << endl;
    }
};

class child2 : public parent1{
public:
    child2() : parent1(){
        cout << "Child Class2" << endl;
    }
};

int main() {
    child1 m;
    child2 n;
    return 0;
}
