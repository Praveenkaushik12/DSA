#include<iostream>
#include<cmath>
using namespace std;

const int MOD = 1000000007; 

long long power(long long num,long long exp){
    if(exp==0){
        return 1;
    }
    long long half = power(num, exp/2);
    if(exp%2==0){
        return (half * half) % MOD;
    }else{
        return (num * half * half) % MOD;
    }
}


int GoodNum(long long num){
    long long ev;
    long long od;
    if(num&1){
        od=num/2;
        ev=(num+1)/2;
    }else{
        od=num/2;
        ev=num/2;
    }
    return ((power(5,ev)%MOD)*(power(4,od)%MOD))%MOD;
}

int main(){
    int result=GoodNum(50);
    cout<<result;
    return 0;
}