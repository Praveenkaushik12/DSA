#include<iostream>
using namespace std;

class parent{
public:
   parent(){
    cout<<"Parent class"<<endl;
   }
};

class child: public parent{
public:
child(){
    cout<<"Child Class"<<endl;
}

};

class Grandchild: public child{
public:
Grandchild(){
    cout<<"Grandchild class"<<endl;
}
};

int main(){
    child c; //single_inheritance
    Grandchild g; //multilevel_inheritance
    
    return 0;
}