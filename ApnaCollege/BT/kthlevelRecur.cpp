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

int Height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int LeftH = Height(root->left);
    int RightH = Height(root->right);

    return max(LeftH, RightH) + 1;
}
void KthOrderHelper(Node*root,int k,int level){
    if(root==nullptr){
        return;
    }
    if(level==k){
        cout<<root->data<<" ";
        return;
    }

    KthOrderHelper(root->left,k,level+1);
    KthOrderHelper(root->right,k,level+1);

}

void KthOrder(Node* root,int k) { //O(n)
    KthOrderHelper(root,k,1);
    cout<<endl;

}




int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int indx = -1;
    Node* ans = buildTree(nodes, indx);
    int k=1;

    KthOrder(ans,k);
    
    return 0;
}
