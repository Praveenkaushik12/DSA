#include <iostream>
using namespace std;

class Rectangle
{
public:
    int l;
    int b;

    // Constructor function is called when object is created.
    // It has same name as class.

    Rectangle()
    { // default constructor
        l = 0;
        b = 0;
    }

    Rectangle(int x, int y)
    { // parameterised constructor
        l = x;
        b = y;
    }

    Rectangle(Rectangle &r)
    { // copy constructor
        l = r.l;
        b = r.b;
    }
    // Destructor is called when object is deleted.
    // can not pass any parameter
    // name ==   ~(class_name)
    ~Rectangle(){
        cout<<"Destructor is called"<<endl;
    }
};

int main()
{

    Rectangle r1;
    cout << r1.l << " " << r1.b << endl;

    Rectangle r2(3, 4);
    cout << r2.l << " " << r2.b << endl;

    Rectangle r3 = r2;
    cout << r3.l << " " << r3.b<<endl;


    return 0;
}