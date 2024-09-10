#include<iostream>
using namespace std;

int RotatedSorted(int arr[],int si,int ei,int target){
    if(si>ei){
        return -1;
    }
    int mid=si+(ei-si)/2;

    if(arr[mid]==target){
            return mid;
    }

    if(arr[si]<=arr[mid]){//L1
        if(arr[si]<=target && target<arr[mid]){
            return RotatedSorted(arr,si,mid-1,target);
        }else{
            return RotatedSorted(arr,mid+1,ei,target);
        }
    }else{
        if(arr[mid]<target && target<=arr[ei]){
            return RotatedSorted(arr,mid+1,ei,target);
        }else{
            return RotatedSorted(arr,si,mid-1,target);
        }
    } 
}


int main(){
    int arr[]={4,5,6,7,0,1,2};
    int reqIndex=RotatedSorted(arr,0,6,0);
    cout<<"Index:"<<reqIndex;
    return 0;
}