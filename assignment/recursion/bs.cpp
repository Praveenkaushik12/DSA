#include<iostream>
using namespace std;

int binarySearch(int arr[],int si,int ei,int key){
    if(si>ei){
        return -1;
    }
    int mid=si+(ei-si)/2;
    if(arr[mid]==key){
        return mid;
    }else if(arr[mid]<key){
        binarySearch(arr,mid+1,ei,key);
    }else{
        binarySearch(arr,si,mid-1,key);
    }
}

int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int key=8;
    cout<<binarySearch(arr,0,6,key);
    return 0;
}