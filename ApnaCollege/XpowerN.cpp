#include<iostream>
using namespace std;

int power(int X,int N){
    if(N==0){
        return 1;
    }
    if(N%2==0){
        return power(X,N/2)*power(X,N/2);
    }else{
        return X*power(X,N/2)*power(X,N/2);
    }
}


int main(){
    int result=power(3,4);
    cout<<result;
}