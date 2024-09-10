#include<iostream>
#include<queue>
using namespace std;

void firstNonrepeating(string str){
    queue<char>q1;
    int freq[26]={0};
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        q1.push(ch);
        freq[ch-'a']++;

        while(!q1.empty() && freq[q1.front()-'a']>1){
            q1.pop();
        }

        if(q1.empty()){
            cout<<"-1"<<endl;
        }else{
            cout<<q1.front()<<endl;
        }

    }

}
int main(){
    string str="aabccxb";
    firstNonrepeating(str);

    return 0;
}