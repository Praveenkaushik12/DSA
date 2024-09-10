#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isDuplicate(string str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch!=')'){
            s.push(ch);
        }else{
            if(s.top()=='('){
                return true;
            }else{
                while(s.top()!='('){
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return false;

}

int main(){
    string s="((a+b))";
    cout<<isDuplicate(s);
    return 0;
}