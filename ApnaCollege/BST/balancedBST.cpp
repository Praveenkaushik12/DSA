#include<iostream>
#include<vector>
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

Node* sortedArrToBST(vector<int>&nums,int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid = start+(end-start)/2;
        Node* curr=new Node(nums[mid]);
        curr->left=sortedArrToBST(nums,start,mid-1);
        curr->right=sortedArrToBST(nums,mid+1,end);
        return curr;
    }


void InorderSeq(Node* root,vector<int>&nums){
    
    if(root==NULL){
        return;
    }
    InorderSeq(root->left,nums); 
    nums.push_back(root->data);
    InorderSeq(root->right,nums);
    
}

void Preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}

int main(){

    Node* root=new Node(6);
    root->left=new Node(5);
    root->left->left=new Node(4);
    root->left->left->left=new Node(3);

    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->right=new Node(9);
    vector<int>nums;
    InorderSeq(root,nums);
    Node* new_root=sortedArrToBST(nums,0,nums.size()-1);
    Preorder(new_root);



    return 0;

}