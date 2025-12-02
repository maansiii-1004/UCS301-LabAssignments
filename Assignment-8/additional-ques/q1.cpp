#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int sumLeftLeaves(Node* root) {
    if (root == NULL) return 0;

    int sum = 0;

    if (root->left != NULL &&
        root->left->left == NULL &&
        root->left->right == NULL) 
    {
        sum += root->left->data;
    }


    sum += sumLeftLeaves(root->left);
    sum += sumLeftLeaves(root->right);

    return sum;
}

int main() {
  
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    cout << "Sum of left leaves = " << sumLeftLeaves(root);

    return 0;
}
