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

Node* buildFromPre(int preorder[], int inorder[], int start, int end, int &preIndex) {
    if (start > end) return NULL;

    Node* root = new Node(preorder[preIndex++]);

    if (start == end) return root;

    int inIndex = searchIndex(inorder, start, end, root->data);

    root->left = buildFromPre(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildFromPre(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[]  = {4, 2, 5, 1, 3};
    int n = 5;

    int preIndex = 0;
    Node* root = buildFromPre(preorder, inorder, 0, n - 1, preIndex);

    cout << "Inorder traversal of constructed tree: ";
    inorderPrint(root);

    return 0;
}
