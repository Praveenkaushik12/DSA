#include<iostream>
#include<vector>
using namespace std;


int UnboundedKnapTab(vector<int>coins,int w){
    int n=coins.size();
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(coins[i-1]<=j){
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];  
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
    vector<int>coins={2};
    int amount=2;

    
    cout<<UnboundedKnapTab(coins,amount);


    return 0;
}