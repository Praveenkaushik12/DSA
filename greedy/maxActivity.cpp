#include<iostream>
#include<vector>
using namespace std;

int maxActivity(vector<int>v1,vector<int>v2){
    int n=v2.size();
    int count=1;
    cout<<"Selecting Activity A0\n";
    int temp=v2[0];

    for(int i=1;i<n;i++){
        if(v1[i]>=temp){
            cout<<"Selecting Activity A"<<i<<endl;
            count++;
            temp=v2[i];   
        }
    }

    return count;
}

int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};

    cout<<maxActivity(start,end);


    return 0;
}