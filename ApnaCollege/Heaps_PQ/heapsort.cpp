#include<iostream>
#include<vector>
using namespace std;


void heapify(int i,vector<int>&arr,int n){
    int left=2*i+1;
    int right=2*i+2;
    int maxi=i;

    if(left<n && arr[left]>arr[maxi]){
        maxi=left;
    }

    if(right<n && arr[right]>arr[maxi]){
        maxi=right;
    }

    if(maxi!=i){
        swap(arr[i],arr[maxi]);
        heapify(maxi,arr,n);
    }

}
void heapSort(vector<int>&arr){
    int n=arr.size();
      
    //step1
    for(int i=n/2-1;i>=0;i--){
        heapify(i,arr,n);
    }

    //step2
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }



}
int main(){
    vector<int>arr={1,4,2,5,3};
    int n=arr.size();
    heapSort(arr);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}