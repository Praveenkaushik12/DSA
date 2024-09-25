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

Node* InsertNode(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }

    if(val < root->data){
        root->left=InsertNode(root->left,val);
    }else{
        root->right=InsertNode(root->right,val);
    }

    return root;
}


Node* buildBST(int arr[],int n){
    Node* root=NULL;

    for(int i=0;i<n;i++){
        root=InsertNode(root,arr[i]);
    }

    return root;
}

void Inorder(Node* root){
    
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    
}

int main(){

    int arr[6]={5,1,3,4,2,7};
    Node* root=buildBST(arr,6);
    Inorder(root);


    return 0;



}