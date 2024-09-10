#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum=0,m;
    int sumEven,sumOdd;
    cin>>n;

    while(n>0){
        m=n%10;
        if(m%2==0){
            sumEven=sum+m;
        }else{
            sumOdd=sum+m;
        }
        n=n/10;    
    }

    cout<<sumEven<<" "<<sumOdd;






    return 0;

}