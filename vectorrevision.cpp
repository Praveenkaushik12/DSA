#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,3,4};
    auto it= v.rend();
    cout<<*(it-1)<<" ";
    return 0;
}