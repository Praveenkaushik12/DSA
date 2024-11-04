#include<iostream>
#include<vector>
using namespace std;


int rodLength(vector<int>prices,int w){
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(i<=j){
                dp[i][j]=max(prices[i-1]+dp[i][j-i],dp[i-1][j]);  
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][w];
}




int main(){


    vector<int>prices={1,5,8,9,10,17,17,20};
    int length=8;

    cout<<rodLength(prices,length);




    return 0;
}