#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* sortedArrToBST(vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    Node* curr = new Node(nums[mid]);
    curr->left = sortedArrToBST(nums, start, mid - 1);
    curr->right = sortedArrToBST(nums, mid + 1, end);
    return curr;
}

void InorderSeq(Node* root, vector<int>& nums) {
    if (root == NULL) {
        return;
    }
    InorderSeq(root->left, nums); 
    nums.push_back(root->data);
    InorderSeq(root->right, nums);
}

vector<int> mergedNodes(vector<int>& nums1, vector<int>& nums2) {
    int i = 0;
    int j = 0;
    vector<int> mergedNodes;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            mergedNodes.push_back(nums1[i++]);
        } else {
            mergedNodes.push_back(nums2[j++]);
        }
    }

    while (i < nums1.size()) {
        mergedNodes.push_back(nums1[i++]);
    }
    while (j < nums2.size()) {
        mergedNodes.push_back(nums2[j++]);
    }
    return mergedNodes;
}

void Inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    vector<int> nums1;
    vector<int> nums2; 
    vector<int> result;

    InorderSeq(root1, nums1);
    InorderSeq(root2, nums2);

    result = mergedNodes(nums1, nums2);

    Node* root = sortedArrToBST(result, 0, result.size() - 1);

    Inorder(root);

    return 0;
}
