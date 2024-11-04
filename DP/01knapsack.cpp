#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>val,vector<int>wt,int w,int n){ //(2^n)

    if(n==0||w==0){
        return 0;
    }

    int itemwt=wt[n-1];
    int itemVal=val[n-1];

    if(itemwt<=w){
        int ans1=knapsack(val,wt,w-itemwt,n-1)+itemVal;

        int ans2=knapsack(val,wt,w,n-1);

        return max(ans1,ans2);
    }else{
        return knapsack(val,wt,w,n-1);
    }
}

int knapsackMem(vector<int>val,vector<int>wt,int w,int n,vector<vector<int>>&dp){ 
    if(n==0||w==0){
        return 0;
    }
    
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    int itemwt=wt[n-1];
    int itemVal=val[n-1];

    if(itemwt<=w){
        int ans1=knapsackMem(val,wt,w-itemwt,n-1,dp)+itemVal;

        int ans2=knapsackMem(val,wt,w,n-1,dp);

        dp[n][w]= max(ans1,ans2);
    }else{
        dp[n][w]= knapsackMem(val,wt,w,n-1,dp);
    }

    return dp[n][w];
}

int knapsackTab(vector<int>val,vector<int>wt,int w,int n){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int itemWt=wt[i-1];
            int itemVal=val[i-1];

            if(itemWt<=j){
                dp[i][j]=max(itemVal+dp[i-1][j-itemWt],dp[i-1][j]);

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
    vector<int>val={15,14,10,45,30};
    vector<int>wt={2,5,1,3,4};
    int W=7;
    int N=5;

    vector<vector<int>>dp(N+1,vector<int>(W+1,-1));

    cout<<knapsackTab(val,wt,W,N);



    return 0;
}