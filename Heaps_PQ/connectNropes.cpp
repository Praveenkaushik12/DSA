#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int connectNropes(vector<int>ropes){
    priority_queue<int,vector<int>,greater<int>>pq(ropes.begin(),ropes.end());
    int count=0;

    while(pq.size()>1){
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();
        count+=min1+min2;

        pq.push(min1+min2);

    }

    return count;
    
}

int main(){
    vector<int>ropes={4,3,2,6};

    cout<<"count:"<<connectNropes(ropes);

    return 0;

}