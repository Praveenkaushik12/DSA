#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>P1,pair<int,int>P2){
    return P1.second<P2.second;
}

int maxChainLength(vector<pair<int,int>>Chain){
    int n=Chain.size();
    int sum=1;
    int currEnd=Chain[0].second;
    cout<<Chain[0].first<<","<<Chain[0].second<<endl;

    for(int i=1;i<n;i++){
        if(Chain[i].first>=currEnd){
            currEnd=Chain[i].second;
            cout<<Chain[i].first<<","<<Chain[i].second<<endl;
            sum++;
        }
    }
     
    return sum;
}

int main(){
    vector<pair<int,int>>chain={{5,24},{39,60},{5,28},{27,40},{50,90}};

    sort(chain.begin(),chain.end(),compare);

    cout<<maxChainLength(chain);

    return 0;
}