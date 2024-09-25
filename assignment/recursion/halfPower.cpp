#include<iostream>
using namespace std;

int halfPower(int n,int e){
    if(e==0){
        return 1;
    }
    if(e%2==0){
        return halfPower(n,e/2)*halfPower(n,e/2);
    }else{
        return n*halfPower(n,e/2);
    }

}

int main(){

    int result=halfPower(25,2);
    cout<<result;

    return 0;
}