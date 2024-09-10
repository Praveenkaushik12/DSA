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
void LevelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q1;
    q1.push(root);
    q1.push(nullptr);

    while (!q1.empty()) {
        Node* curr = q1.front();
        q1.pop();

        if (curr == nullptr) {
            cout << endl;
            if (!q1.empty()) {
                q1.push(nullptr);
            }
        } else {
            cout << curr->data << " ";
            if (curr->left != nullptr) {
                q1.push(curr->left);
            }
            if (curr->right != nullptr) {
                q1.push(curr->right);
            }
        }
    }
}

int TransformSum(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftold = TransformSum(root->left);
    int rightold = TransformSum(root->right);

    int currOld = root->data;
    
    // Check if left or right child exists before accessing their data
    int leftData = (root->left != nullptr) ? root->left->data : 0;
    int rightData = (root->right != nullptr) ? root->right->data : 0;

    root->data = leftold + rightold + leftData + rightData;

    return currOld;
}



int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int indx = -1;
    Node* ans = buildTree(nodes, indx);
   
   TransformSum(ans);
   LevelOrder(ans);

    
    return 0;
}
