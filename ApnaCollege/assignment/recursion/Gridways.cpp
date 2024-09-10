#include<iostream>
using namespace std;

int countWays(int i,int j,int n,int m,string ans){
    if(i>=n || j>=m){
        return 0;
    }
    if(i==n-1 && j==m-1){
        cout<<ans<<endl;
        return 1;
    }

    //right
    int r1=countWays(i,j+1,n,m,ans+'R');
    //down
    int r2=countWays(i+1,j,n,m,ans+'D');

    return r1+r2;
}

int main(){
    int n=4;
    int m=3;
    string ans="";
    int result=countWays(0,0,n,m,ans);
    cout<<result;

    return 0;
}