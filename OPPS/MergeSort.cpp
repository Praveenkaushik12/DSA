#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int lb,int mid,int ub){
    int b[ub];
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            k++;
            j++;
        }
    }else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }

    for(k=lb;k<=ub;k++){
        a[k]=b[k];
    }

}

void mergeSort(int a[],int left,int right){
    if(left>=right) return;
    int mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid,right); 
}

int main(){
    int a[]={12,11,13,5,6,7};
    int n= sizeof(a)/sizeof(a[0]);

    cout<<"Current Array:\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    mergeSort(a,0,n-1);
    cout<<"\nSorted Array:\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}