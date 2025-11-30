#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to check BST property using range limits
bool isBSTUtil(Node* node, int min, int max) {
    if (node == nullptr)
        return true;
    if (node->data <= min || node->data >= max)
        return false;
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -100000, 100000);
}

int main() {
    // Example binary tree
    Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    if (isBST(root))
        cout << "The given tree is a Binary Search Tree." << endl;
    else
        cout << "The given tree is NOT a Binary Search Tree." << endl;

    return 0;
}
