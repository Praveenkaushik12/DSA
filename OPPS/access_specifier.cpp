#include<iostream>
using namespace std;

class accessSpecifier{
    private:
    int x;
    public:
    int y;
    protected:
    int z;
};

class Child1: public accessSpecifier{
    //x will not be accessible
    //y will be public.
    //z will be protected.
};
class Child2: protected accessSpecifier{
    //x will not be accessible
    //y will be protected.
    //z will be protected.
};
class Child1: private accessSpecifier{
    //x will not be accessible
    //y will be private.
    //z will be private.
};

int main(){
    return 0;
}