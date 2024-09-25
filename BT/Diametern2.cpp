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
        left=right=nullptr;
    }

};


Node* buildTree(vector<int>&nodes,int &index){
    // int n=nodes.size();
    index++;
    if(nodes[index]==-1){
        return nullptr;
    }
    Node* currNode=new Node(nodes[index]);
    currNode->left=buildTree(nodes,index);
    currNode->right=buildTree(nodes,index);

    return currNode;

}

int height(Node* root){
    if(root==nullptr){
        return 0;
    }
    int LeftH=height(root->left);
    int RightH=height(root->right);

    return max(LeftH,RightH) + 1;
}

int Diameter(Node* root){
    if(root==nullptr){
        return 0;
    }
    int rootD=height(root->left)+height(root->right)+1;
    int LeftD=Diameter(root->left);
    int RightD=Diameter(root->right);

    return max(rootD,max(LeftD,RightD));
}



int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int indx = -1;
    Node* ans = buildTree(nodes, indx);

    cout<<ans->data<<endl;
    cout<<"Diameter(O(n2)):"<<Diameter(ans)<<endl;

    return 0;
}
