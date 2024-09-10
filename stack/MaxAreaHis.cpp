#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void LeftRight(vector<int>Hist,vector<int>&nsl,vector<int>&nsr){
    int n=Hist.size();
    stack<int>s;
    
    //left
    for(int i=0;i<n;i++){
        while(!s.empty() && Hist[i]<=Hist[s.top()]){
            s.pop();
        }
        if(s.empty()){
            s.push(i);
        }else{
            nsl[i]=s.top();
            s.push(i);
        }
    }

    while(!s.empty()){
        s.pop();
    }

    //right
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && Hist[i]<=Hist[s.top()]){
            s.pop();
        }
        if(s.empty()){
            s.push(i);
        }else{
            nsr[i]=s.top();
            s.push(i);
        }
    }

   
}

int MaxHistogramArea(vector<int>nums){
    int n=nums.size();
    int area,result=0;
    int breadth;
    vector<int>nsl(n,-1);
    vector<int>nsr(n,n);

    LeftRight(nums,nsl,nsr);

    for(int i=0;i<n;i++){
        breadth=nsr[i]-nsl[i]-1;
        area=nums[i]*breadth;
        result=max(result,area);  
    }

    return result;

}

int main(){
    vector<int>Hist={2,1,5,6,2,3};
    cout<<MaxHistogramArea(Hist);
    return 0;
}