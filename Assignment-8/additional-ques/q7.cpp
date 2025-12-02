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

// Convert BST to DLL (inorder)
void bstToDll(Node* root, Node* &head, Node* &prev) {
    if (!root) return;

    bstToDll(root->left, head, prev);

    if (!prev) head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDll(root->right, head, prev);
}

// Merge two sorted DLLs
Node* mergeDLL(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node *head = NULL, *tail = NULL;

    if (h1->data < h2->data) {
        head = tail = h1;
        h1 = h1->right;
    } else {
        head = tail = h2;
        h2 = h2->right;
    }

    while (h1 && h2) {
        if (h1->data < h2->data) {
            tail->right = h1;
            h1->left = tail;
            tail = h1;
            h1 = h1->right;
        } else {
            tail->right = h2;
            h2->left = tail;
            tail = h2;
            h2 = h2->right;
        }
    }

    if (h1) {
        tail->right = h1;
        h1->left = tail;
    }
    if (h2) {
        tail->right = h2;
        h2->left = tail;
    }

    return head;
}

Node* mergeBSTs(Node* root1, Node* root2) {
    Node *head1 = NULL, *prev1 = NULL;
    Node *head2 = NULL, *prev2 = NULL;

    bstToDll(root1, head1, prev1);
    bstToDll(root2, head2, prev2);

    return mergeDLL(head1, head2);
}

void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main() {
    // BST 1
    Node* bst1 = new Node(2);
    bst1->left = new Node(1);
    bst1->right = new Node(4);

    // BST 2
    Node* bst2 = new Node(3);
    bst2->left = new Node(0);
    bst2->right = new Node(5);

    Node* merged = mergeBSTs(bst1, bst2);

    cout << "Merged sorted DLL: ";
    printDLL(merged);

    return 0;
}
