#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> &arr,long long k){
    map<long long, int> preSumMap;
    long long sum =0;
    int maxLen = 0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum ==k){
            maxLen=max(maxLen,i+1);
        }
        long long rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len = i-preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxLen;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }
    long long k;
    cout<<"Enter the sum"<<endl;
    cin>>k;
    int ans=longestSubarrayWithSumK(arr,k);
    cout<<ans;
    return 0;
}