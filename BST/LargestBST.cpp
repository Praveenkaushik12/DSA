#include<iostream>
#include<climits>
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

class Info{
public:
    bool isBST;
    int min;
    int max;
    int sz;
    
    Info(bool isBST,int min,int max,int sz){
        this->isBST=isBST;
        this->min=min;
        this->max=max;
        this->sz=sz;
    }
};

static int maxLen;

Info* largestBST(Node* root){

    if(root==NULL){
        return new Info(true,INT_MAX,INT_MIN,0);
    }
    Info* leftinfo=largestBST(root->left);
    Info* rightinfo=largestBST(root->right);

    int currMin=min(root->data,min(leftinfo->min,rightinfo->min));
    int currMax=max(root->data,max(leftinfo->max,rightinfo->max));
    
    int currSize=leftinfo->sz+rightinfo->sz+1;


    if(leftinfo->isBST==true &&
     rightinfo->isBST==true &&
      leftinfo->max <root->data && 
      rightinfo->min > root->data){
        maxLen=max(maxLen,currSize);

        return new Info(true,currMin,currMax,currSize);

    }
    

    return new Info(false,currMin,currMax,currSize);

}

int main(){
    Node* root=new Node(50);
    root->left=new Node(30);
    root->left->left=new Node(5);
    root->left->right=new Node(20);

    root->right=new Node(60);
    root->right->left=new Node(45);
    root->right->right=new Node(70);
    root->right->right->left=new Node(65);
    root->right->right->right=new Node(80);

    largestBST(root);

    cout<<maxLen<<" ";

    return 0;
}