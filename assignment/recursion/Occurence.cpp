#include<iostream>
using namespace std;

void occurence(int arr[],int si,int ei,int key){
    if(si>ei){
        return;
    }
    if(arr[si]==key){
        cout<<si<<" ";
    }
    occurence(arr,si+1,ei,key);
}

int main(){
    int arr[10]={3,2,4,5,6,2,7,2,2};
    int key=2;
    occurence(arr,0,9,2);
    return 0;
}