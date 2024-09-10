#include<bits/stdc++.h>
using namespace std;

int main(){
    // NOt SOlved!!
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }
    int k;
    cin>>k; //3
    int temp[k];
    if(k>n){//3<5
       k=k%n; 
    }
    //k=3
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    } 
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    } 
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-(n-k)];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;

}