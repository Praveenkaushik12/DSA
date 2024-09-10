#include<iostream>
using namespace std;


void clearbit(int num,int i,int j){
     int a=(~0)<<(j+1);
     int b=(1<<i)-1;

     int mask=a|b;
     num=num&mask;

     cout<<num<<endl;
}


int main(){

    clearbit(31,1,3);
   

    return 0;
}