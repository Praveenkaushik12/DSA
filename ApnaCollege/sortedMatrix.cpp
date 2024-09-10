#include<iostream>
using namespace std;

bool searchTarget(int matrix[][4],int n,int m,int target){
    int r=0;
    int c=m-1;
    while(r<n && c>=0){
        int start=matrix[r][c];
        if(start==target){
            cout<<r<<","<<c<<endl;
            return true;
        }
        if(start>target){
            c--;
        }
        if(start<target){
            r++;
        }
    }
    cout<<"-1";
    return false;
}


int main(){
    int matrix[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    searchTarget(matrix,4,4,12);
    return 0;

}