#include<iostream>
using namespace std;

int tile(int n){
    if(n==0||n==1){
        return 1;
    }
    int a=tile(n-1);
    int b=tile(n-2);

    return a+b;    
}

int main(){
    int result=tile(4);
    cout<<result;
    return 0;
}