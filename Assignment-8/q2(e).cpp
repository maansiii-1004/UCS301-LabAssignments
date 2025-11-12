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

Node* findMax(Node* node) {
    while (node && node->right)
        node = node->right;
    return node;
}

// Find Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    if (root && root->left)
        predecessor = findMax(root->left);
    return predecessor;
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

    Node* target = root->right; // node 70
    Node* pred = inorderPredecessor(root, target);
    if (pred)
        cout << "Inorder Predecessor of " << target->data << " is " << pred->data << endl;
    else
        cout << "No Predecessor found\n";
    return 0;
}
