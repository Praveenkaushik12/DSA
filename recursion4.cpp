#include<bits/stdc++.h>
using namespace std;

void f(int n,int i){
    if(n< i)return;
    else 
    f(n-1,i);
    cout<<n<<endl;
    
}


int main(){
    int n;
    cin>>n;
    f(n,1);

}