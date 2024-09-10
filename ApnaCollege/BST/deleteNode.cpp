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

Node* getInorderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }

    return root;

}

Node* deleteNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data>val){
        root->left=deleteNode(root->left,val); 
    }else if(root->data<val){
        root->right=deleteNode(root->right,val);
    }else{
        //root==val
        //case1: 0 children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //case2: 1 children
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL ? root->right : root->left;
        }

        //case3: 2 childrens

        Node* IS=getInorderSuccessor(root->right);
        root->data=IS->data;
        root->right=deleteNode(root->right,IS->data); //case1 case2
        return root;
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
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    Inorder(root);
    cout<<endl;
    root=deleteNode(root,10);
    Inorder(root);

    return 0;


}