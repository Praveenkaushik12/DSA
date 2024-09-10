#include<iostream>
using namespace std;

int countSubstringfromIndex(string s,int start,int end){
    if(end==s.length()){
        return 0;
    }

    if(s[start]==s[end]){
        return 1+countSubstringfromIndex(s,start,end+1);
    }else{
        return countSubstringfromIndex(s,start,end+1);
    }
}

int countallSubstrings(string s){
    int totalcount=0;
    for(int i=0;i<s.length();i++){
        totalcount+=countSubstringfromIndex(s,i,i);
    }
    return totalcount;
}

int main(){
    string str="abcab";
    int result=countallSubstrings(str);
    cout<<result;
    
    
    return 0;
}