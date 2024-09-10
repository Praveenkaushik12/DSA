#include<bits/stdc++.h>
using namespace std;

int MinIndianCoin(vector<int>coins,int V){
    int n=coins.size()-1;
    int ans=0;
    for(int i=n;i>=0 && V>0;i--){
        if(V>=coins[i]){
            cout<<"Coins:"<<coins[i]<<endl;
            ans+=V/coins[i];
            V=V%coins[i];
        }
    }
    return ans;

}

int main(){
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int value=2521;

    cout<<MinIndianCoin(coins,value);



    return 0;
}