#include<iostream>
using namespace std;

class parent1 {
public:
    parent1() {
        cout << "Parent class1" << endl;
    }
};

class parent2 {
public:
    parent2() {
        cout << "Parent class2" << endl;
    }
};

class child : public parent1, public parent2 {
public:
    child() : parent1(), parent2() {
        cout << "Child Class" << endl;
    }
};

int main() {
    child m;
    return 0;
}
