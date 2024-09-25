#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node* sortedArrToBST(int nums[],int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid = start+(end-start)/2;
        Node* curr=new Node(nums[mid]);
        curr->left=sortedArrToBST(nums,start,mid-1);
        curr->right=sortedArrToBST(nums,mid+1,end);
        return curr;
    }


void Preorder(Node* root){
    
    if(root==NULL){
        return;
    }
     
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
    
}

int main(){

    int arr[5]={-10,-3,0,5,9};
    Node* root=sortedArrToBST(arr,0,4);
    Preorder(root);
    return 0;

}