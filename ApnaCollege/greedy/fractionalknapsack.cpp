#include <bits/stdc++.h>
using namespace std;

bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first>p2.first;
}
int fractionalKnapsack(vector<int>val,vector<int>wt,int W){
    int n=val.size();
    int ans=0;
    vector<pair<double,int>>ratio(n,make_pair(0.0,0));

    for(int i=0;i<n;i++){
        double r= val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),compare);

    for(int i=0;i<n;i++){
        int indx=ratio[i].second;
        if(wt[indx]<=W){
            ans+=val[indx];
            W-=wt[indx];
        }else{
            ans+=ratio[i].first*W;
            W=0;
            break;
        }
    }
    return ans;

}

int main(){
    vector<int>value={60,100,120};
    vector<int>weight={10,20,30};
    int W=50;


    cout<< fractionalKnapsack(value,weight,W)<<endl;


    return 0;

}
