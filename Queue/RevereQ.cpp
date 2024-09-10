#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int>&q1){
    stack<int>s1;

    while(!q1.empty()){
        s1.push(q1.front());
        q1.pop();
    }

    while(!s1.empty()){
        q1.push(s1.top());
        s1.pop();
    }

}

int main(){

    queue<int>q1;

    for(int i=1;i<6;i++){
        q1.push(i);
    }

    reverse(q1);

    for(int i=1;i<6;i++){
        cout<<q1.front()<<"\t";
        q1.pop();
    }

    return 0;
}