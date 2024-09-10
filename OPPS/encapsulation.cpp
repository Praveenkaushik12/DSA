#include<iostream>
using namespace std;
//ENCAPSULATION-->binding methods and variable into a single unit called class.
//data is only accessible from the class methods.
//also leads to data abstraction and hiding.
class num{
    int x;
public:
    void set(int n){
        x=n;
    }

    int get(){
        return x;
    }
};

int main(){
    num obj1;
    obj1.set(5);
    cout<<obj1.get()<<endl;

    return 0;
}