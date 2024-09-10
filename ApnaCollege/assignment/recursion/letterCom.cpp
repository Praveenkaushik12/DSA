#include<iostream>
#include<vector>
using namespace std;

void bfs(int pos, int len, string ans,string Dig,vector<vector<char>>L){
    if(pos==len){
        cout<<ans<<" ";
    }else{
        vector<char>letters=L[Dig[pos]-'0'];
        for(int i=0;i<letters.size();i++){
            bfs(pos+1,len,ans+letters[i],Dig,L);
        }
    }
}

void letterCombination(string digit,vector<vector<char>>L){
    int len=digit.size();
    if(len==0){
        cout<<"";
        return;
    }
    string ans="";
    bfs(0,len,ans,digit,L);
}

int main(){
    vector<vector<char>> L = {
        {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, 
        {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, 
        {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
    };
    string digits = "234";
    letterCombination(digits, L);

    return 0;

}