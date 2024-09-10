#include<iostream>
#include <climits>
using namespace std;

void countingSort(int arr[],int n){
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    
    }

    int freqArr[n+1]={0};

    for(int i=0;i<n;i++){
        freqArr[arr[i]]++;
    }

    for(int i=mini,j=0;i<=maxi;i++){
        while(freqArr[i]>0){
            arr[j++]=i;
            freqArr[i]--;
            
        }
    }
    
}

int main(){
    int arr[8]={1,4,5,2,6,3,1,2};
    countingSort(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}