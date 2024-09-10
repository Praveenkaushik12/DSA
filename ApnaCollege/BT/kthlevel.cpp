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


void KthOrder(Node* root,int k) {
    if(root==nullptr){
        return ;
    }

    queue<Node*>q;
    q.push(root);
    int level=1;


    while(!q.empty()){
        int n=q.size();
        if(level==k){
            for(int i=0;i<n;i++){
                Node* curr=q.front();
                q.pop();
                cout<<curr->data<<"\t";
            }
            cout<<endl;
            return;
        }else{
            for(int i=0;i<n;i++){
                Node* curr=q.front();
                q.pop();
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
            level++;
        }
    }
}




int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int indx = -1;
    Node* ans = buildTree(nodes, indx);
    int k=3;
    
    if(k<1 || k>Height(ans)){
        cout<<"Invalid Level"<<endl;
    }else{
        cout << "KthOrder:" << endl;
        KthOrder(ans,k);
        cout << endl;
    }

    


    return 0;
}
