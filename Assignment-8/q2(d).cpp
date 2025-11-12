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

Node* insert(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

Node* findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Find Inorder Successor
Node* inorderSuccessor(Node* root, Node* target) {
    Node* successor = nullptr;
    while (root != nullptr) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    if (root && root->right)
        successor = findMin(root->right);
    return successor;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    Node* target = root->left; // node 30
    Node* succ = inorderSuccessor(root, target);
    if (succ)
        cout << "Inorder Successor of " << target->data << " is " << succ->data << endl;
    else
        cout << "No Successor found\n";
    return 0;
}
