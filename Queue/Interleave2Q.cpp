#include<iostream>
#include<queue>
using namespace std;

void Interleave2Queue(queue<int>&q1){
    int n=q1.size();
    queue<int>que1;

    for(int i=0;i<n/2;i++){
        que1.push(q1.front());
        q1.pop();
    }

    while(!que1.empty()){
        q1.push(que1.front());
        que1.pop();
        q1.push(q1.front());
        q1.pop();
    }
    
    while(!q1.empty()){
        cout<<q1.front()<<endl;
        q1.pop();
    }
}

int main(){
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.push(7);
    q1.push(8);
    q1.push(9);
    q1.push(10);

    Interleave2Queue(q1);


    return 0;
}