#include<iostream>
using namespace std;

void binStrings(int n,int lastdigit,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(lastdigit!=1){
        binStrings(n-1,0,ans+'0');
        binStrings(n-1,1,ans+'1');
    }else{
        binStrings(n-1,0,ans+'0');
    }

}

void binStringsnew(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(ans[ans.size()-1]!='1'){
        binStringsnew(n-1,ans+'0');
        binStringsnew(n-1,ans+'1');
    }else{
        binStringsnew(n-1,ans+'0');
    }

}


int main(){
    string ans="";
    binStrings(3,0,ans);
    cout<<"----------"<<endl;
    binStringsnew(2,ans);
    

    return 0;
}