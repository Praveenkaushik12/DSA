#include<bits/stdc++.h>
using namespace std;

void f(int n,int i){
    if(n>=i) cout<<n<<endl;
    else return;
    f(n-1,i);
}


int main(){
    int n;
    cin>>n;
    f(n,1);

}