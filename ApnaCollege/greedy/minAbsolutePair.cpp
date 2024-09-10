#include<bits/stdc++.h>
using namespace std;

int minAbsolutePair(vector<int>A,vector<int>B){
    int n=A.size();
    vector<pair<int,int>>Min(n,make_pair(0,0));
    int sum=0;
    for(int i=0;i<n;i++){
        Min[i]=make_pair(A[i],B[i]);
        sum+=abs(Min[i].first-Min[i].second);
    }
    return sum;
}


int main(){
    vector<int>A={1,2,3};
    vector<int>B={3,1,2};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());


   cout<<minAbsolutePair(A,B);

    return 0;
}