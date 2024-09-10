#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second>p2.second;
}

int jobseq(vector<pair<int,int>>job){
    int n=job.size();
    int safeSeq=0;
    int ans=job[0].second;
    for(int i=1;i<n;i++){
        if(job[i].first>safeSeq){
            ans+=job[i].second;
            safeSeq++;
        }
    }
    return ans;
}

int main(){
    vector<pair<int,int>>job={{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};
    sort(job.begin(),job.end(),compare);

   cout<<jobseq(job)<<endl;

    return 0;
}