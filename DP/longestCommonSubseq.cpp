#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int subseq(string str1,string str2){
    if(str1.size()==0||str2.size()==0){
        return 0;
    }
    int n=str1.size();
    int m=str2.size();

    if(str1[n-1]==str2[m-1]){
        return 1+subseq(str1.substr(0,n-1),str2.substr(0,m-1));
    }else{
        int ans1=subseq(str1,str2.substr(0,m-1));
        int ans2=subseq(str1.substr(0,n-1),str2);

        return max(ans1,ans2);
    }
}

int subseqMem(vector<vector<int>>&dp,string str1,string str2){ //O(n*m)
   if(str1.size()==0||str2.size()==0){
        return 0;
    }
    int n=str1.size();
    int m=str2.size();

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[n-1]==str2[m-1]){
        dp[n][m]=1+subseqMem(dp,str1.substr(0,n-1),str2.substr(0,m-1));
    }else{
        int ans1=subseqMem(dp,str1,str2.substr(0,m-1));
        int ans2=subseqMem(dp,str1.substr(0,n-1),str2);

        dp[n][m]= max(ans1,ans2);
    }

    return dp[n][m];
}


int subseqTab(string str1,string str2){
   
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][m];
}

int main(){
    string str1="abcd";
    string str2="aceb";
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    cout<<subseqTab(str1,str2)<<endl;

    // for (int i = 0; i <= str1.size(); i++) {
    //     for (int j = 0; j <= str2.size(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout<<subseq(str1,str2);

    return 0;
}