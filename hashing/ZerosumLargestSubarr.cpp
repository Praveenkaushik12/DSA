#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

int largestSub(vector<int>&arr){
    unordered_map<int,int>mp;
    int sum=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];

        if(mp.count(sum)){
            int currLen=i-mp[sum];
            ans=max(ans,currLen);
        }else{
            mp[sum]=i;
        }
        
    }
    return ans;
}



int main(){
    vector<int>arr={15,2,-2,-8,1,7,10};
    cout<<largestSub(arr);
   
    return 0;

}