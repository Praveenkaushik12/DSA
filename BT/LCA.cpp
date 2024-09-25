#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* buildTree(vector<int>& nodes, int& indx) {
    indx++;

    if (nodes[indx] == -1) {
        return nullptr;
    }

    Node* currNode = new Node(nodes[indx]);
    currNode->left = buildTree(nodes, indx);
    currNode->right = buildTree(nodes, indx);

    return currNode;
}

bool rootToNode(Node* root,int n,vector<int>&path){
    if(root==nullptr){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }

    int left=rootToNode(root->left,n,path);
    int right=rootToNode(root->right,n,path);

    if(left||right){
        return true;
    }

    path.pop_back();
    return false;

}
int LeastCommonAncester(Node* root,int n1,int n2){ //O(n) O(1)
    vector<int>path1;
    vector<int>path2;
    
    rootToNode(root,n1,path1);
    rootToNode(root,n2,path2);

    int lca=-1;
    for(int i=0,j=0;i<path1.size()&& j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
}

Node* LCA2(Node* root,int n1,int n2){ //O(n) O(1)
    if(root==nullptr){
        return nullptr;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* left=LCA2(root->left,n1,n2);
    Node* right=LCA2(root->right,n1,n2);

    if(left!=nullptr && right!=nullptr){
        return root;
    }

    return left==nullptr?right:left;
}



int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int indx = -1;
    Node* ans = buildTree(nodes, indx);
    int k=1;
    cout<<LCA2(ans,5,6)->data;

    
    return 0;
}
