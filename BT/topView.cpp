#include <iostream>
#include <vector>
#include<map>
#include<queue>
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

Node* buildTree(const vector<int>& nodes, int& index) {
    index++;
    if (index >= nodes.size() || nodes[index] == -1) {
        return nullptr;
    }
    Node* currNode = new Node(nodes[index]);
    currNode->left = buildTree(nodes, index);
    currNode->right = buildTree(nodes, index);

    return currNode;
}

void TopView(Node* root){
    //queue->pair(Node->data,Horizontal Distance)
    queue<pair<Node*,int>>q;
    //map-->(key->Horizontal Distance),(Value->Node->data)
    map<int,int>m;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>curr=q.front();
        q.pop();
        
        Node* currNode=curr.first;
        int HD=curr.second;

        if(m.count(HD)==0){
            m[HD]=currNode->data;
        }

        if(currNode->left!=NULL){
            pair<Node*,int>left=make_pair(currNode->left,HD-1);
            q.push(left);
        }

        if(currNode->right!=NULL){
            pair<Node*,int>right=make_pair(currNode->right,HD+1);
            q.push(right);
        }

    }

    for(auto it:m){
        cout<<it.second<<"\t";
    }

}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = -1;

    Node* ans = buildTree(nodes, index);

    TopView(ans);

    // Clean up
    // Ideally, you should write a function to delete the entire tree to avoid memory leaks.

    return 0;
}
