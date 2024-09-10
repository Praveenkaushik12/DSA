#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    map<char, int> mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]-'a'] +=1;
    }
     
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        char c;
        cin>>c;

        cout<<mpp[c-'a'] <<endl;
    }

    return 0;
}