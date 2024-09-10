#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int>stk1;
    stack<int>stk2;

    public:
    void push(int data){
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }

        stk1.push(data);

        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    void pop(){
        stk1.pop();
    }

    int first(){
        return stk1.top();
    }

    bool empty(){
        return stk1.empty();
    }


};


int main(){
   Queue q1;
   q1.push(1);
   q1.push(2);
   q1.push(3);

   while(!q1.empty()){
    cout<<q1.first()<<endl;
    q1.pop();
   }

   return 0;

}