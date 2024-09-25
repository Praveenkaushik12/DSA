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

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}

void Inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    Inorder(root->left);
    cout << root->data << "\t";
    Inorder(root->right);
}

void Postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << "\t";
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

int Height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int LeftH = Height(root->left);
    int RightH = Height(root->right);

    return max(LeftH, RightH) + 1;
}

int Sum(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int LeftS= Sum(root->left);
    int RightS = Sum(root->right);

    return LeftS+RightS+root->data;
}



int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int indx = -1;
    Node* ans = buildTree(nodes, indx);

    // cout << "Preorder: ";
    // preorder(ans);
    // cout << endl;

    // cout << "Inorder: ";
    // Inorder(ans);
    // cout << endl;

    // cout << "Postorder: ";
    // Postorder(ans);
    // cout << endl;

    cout << "LevelOrder:" << endl;
    LevelOrder(ans);
    cout << endl;

    cout << "Height: " << Height(ans) << endl;
    cout << "Sum: " << Sum(ans) << endl;

    return 0;
}
