#include<iostream>
using namespace std;


int peakElm(int arr[],int n){
    int i=0;
    if(n==1){
        return 0;
    }
    if(arr[0]>arr[1]){
        return 0;
    }
    if(arr[n-1]>arr[n-2]){
        return n-1;
    }

    int lb=1;
    int ub=n-2;
    while(lb<=ub){
        int mid=ub+(lb-ub)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid]<arr[mid+1]){
            lb=mid+1;
        }else if(arr[mid]<arr[mid-1]){
            ub=mid-1;
        }else{
            ub=mid-1;
        }
    }
    return -1;  
}
int main(){
    int arr[]={1,2,1,3,5,6,4};
    cout<<peakElm(arr,7);
    return 0;
}