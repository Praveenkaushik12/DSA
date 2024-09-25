#include<iostream>
using namespace std;

bool  isAnagram(string s1,string s2 ){
    if(s1.length()!=s2.length()){
        cout<<"Not Anagram!"<<endl;
        return false;
    }else{
        int count[26]={'0'};
        for(int i=0;i<s1.length();i++){
            count[s1[i]-'a']++;
        }


        for(int i=0;i<s2.length();i++){
            if(count[s2[i]-'a']==0){
                cout<<"Not Anagram!"<<endl;
                return false;
            }else{
                count[s2[i]-'a']--;
            }  
        }
    }
    cout<<"Anagram!"<<endl;
    return true;
}

int main(){
    string s1="rat";
    string s2="tar";
    isAnagram(s1,s2);
    return 0;
}