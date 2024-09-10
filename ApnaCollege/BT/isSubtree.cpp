#include <iostream>
#include <vector>
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

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    if (root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root1, Node* root2) {
    if (root1 == nullptr) {
        return false;
    }

    if (isIdentical(root1, root2)) {
        return true;
    }

    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = -1;

    Node* subtree = new Node(2);
    subtree->left = new Node(4);
    subtree->right = new Node(5); 
    Node* ans = buildTree(nodes, index);
    cout << (isSubtree(ans, subtree) ? "True" : "False") << endl;

    // Clean up
    // Ideally, you should write a function to delete the entire tree to avoid memory leaks.

    return 0;
}
