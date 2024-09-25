#include<iostream>
using namespace std;

void subsets(string str,string subset){
    int n=str.size();
    if(str.size()==0){
        cout<<subset<<" ";
        return;
    }
    char ch=str[0];
    //yes
    subsets(str.substr(1,n-1),subset+ch);
    //no
    subsets(str.substr(1,n-1),subset);
}
int main(){
    string str="abc";
    int n=str.size();
    string substring="";
    subsets(str,substring);
    return 0;
}