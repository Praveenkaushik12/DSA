#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int lb,int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;

    if(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(a[start],a[end]);
        }
    }
    swap(a[lb],a[end]);
    return end;

}

void quickSort(int a[],int lb,int ub){
    if(lb<ub){
       int loc=partition(a,lb,ub);
       quickSort(a,lb,loc-1);
       quickSort(a,lb+1,ub);
    }
}

int main(){
    int a[]={10,7,8,9,1,5};
    int n=sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}