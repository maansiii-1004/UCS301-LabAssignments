#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int searchIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == value) return i;
    return -1;
}

Node* buildFromPost(int inorder[], int postorder[], int start, int end, int &postIndex) {
    if (start > end) return NULL;

    Node* root = new Node(postorder[postIndex--]);

    if (start == end) return root;

    int inIndex = searchIndex(inorder, start, end, root->data);

    root->right = buildFromPost(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildFromPost(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    int inorder[]   = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int n = 5;

    int postIndex = n - 1;
    Node* root = buildFromPost(inorder, postorder, 0, n - 1, postIndex);

    cout << "Inorder traversal of constructed tree: ";
    inorderPrint(root);

    return 0;
}
