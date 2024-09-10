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

void printResult(vector<int>&result){
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

void rootoleafHelper(Node* root,vector<int>&result){
    if(root==NULL){
        return;
    }

    result.push_back(root->data);

    //leaf
    if(root->left==NULL && root->right==NULL){
        printResult(result);
        result.pop_back();
        return ;
    }

    rootoleafHelper(root->left,result);
    rootoleafHelper(root->right,result);


    result.pop_back();
}

void rootToleaf(Node* root){
    vector<int>result;
    rootoleafHelper(root,result); 
}

int main(){

    int arr[3]={2,1,3};
    Node* root=buildBST(arr,3);
    // Inorder(root);

    rootToleaf(root);

    return 0;



}