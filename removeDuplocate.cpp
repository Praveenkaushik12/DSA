#include<iostream>
using namespace std;

void removeDuplication(string S,string ans,int i,int map[26]){
    int n=S.size();
    if(i==n){
        cout<<ans;
        return;
    }
    int index=(int)(S[i]-'a');
    if(map[index]){
        removeDuplication(S,ans,i+1,map);
        
    }else{
        map[index]=true;
        removeDuplication(S,ans+S[i],i+1,map);
    }
    
}


int main(){
    string s="appnnacollege";
    int map[26]={false};
    string ans="";
    removeDuplication(s,ans,0,map);
    return 0;
}